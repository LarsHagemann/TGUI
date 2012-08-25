/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (VDV_B@hotmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _TGUI_COMBO_BOX_INCLUDED_
#define _TGUI_COMBO_BOX_INCLUDED_


// TODO: Fix scaling. This cannot be done before scaling is fixed in ListBox.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct TGUI_API ComboBox : public OBJECT, OBJECT_BORDERS
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ComboBox();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ComboBox(const ComboBox& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~ComboBox();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ComboBox& operator= (const ComboBox& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ComboBox* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Loads the combo box.
        ///
        /// \param comboBoxPathname   The path to the folder that contains the arrow image(s).
        ///                           The folder must also contain an info.txt file, which will give more information about the comb box.
        /// \param width              The width of the combo box (borders included).
        /// \param height             The height of the combo box (borders included).
        /// \param nrOfItemsToDisplay The amount of items that are displayed when you click on the arrow.
        ///                           If there is no scrollbar then this will also be the maximum amount of items that the combo box can contain.
        /// \param scrollbarPathname  The ScrollbarPathname is the pathname needed to load the scrollbar.
        ///                           If not provided then there will be no possibility to scroll, thus no items will be added when the combo box is full.
        /// \return
        ///        - true on success
        ///        - false when the pathname is empty
        ///        - false when the info.txt file was not found
        ///        - false when the images couldn't be loaded
        ///        - false when scrollbar couldn't be loaded (only if \a scrollbarPathname isn't empty)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool load(const std::string comboBoxPathname,
                          float width,
                          float height,
                          const unsigned int nrOfItemsInListToDisplay = 10,
                          const std::string scrollbarPathname = "");


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the combo box.
        ///
        /// \param width   The new width of the combo box (borders included)
        /// \param height  The new height of the combo box (borders included)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the combo box, unaffected by scaling.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2u getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the combo box, after the scaling transformation.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getScaledSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the pathname that was used to load the combo box.
        ///
        /// When the combo box has not been loaded yet then this function will return an empty string.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::string getLoadedPathname() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the pathname that was used to load the scrollbar.
        ///
        /// When no scrollbar was loaded then this function will return an empty string.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::string getLoadedScrollbarPathname() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the number of items that are displayed in the list.
        ///
        /// When there is no scrollbar then this is the maximum number of items.
        /// If there is one, then it will only become visible when there are more items than this number.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setItemsToDisplay(const unsigned int nrOfItemsInListToDisplay);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the number of items that are displayed in the list.
        ///
        /// When there is no scrollbar then this is the maximum number of items.
        /// If there is one, then it will only become visible when there are more items than this number.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getItemsToDisplay() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the colors that are used in the combo box.
        ///
        /// \param backgroundColor          The color of the background of the combo box
        /// \param textColor                The color of the text
        /// \param selectedBackgroundColor  The color of the background of the selected item in the list
        /// \param selectedTextColor        The color of the text when it is selected in the list
        /// \param borderColor              The color of the borders
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void changeColors(const sf::Color& backgroundColor         = sf::Color::White,
                                  const sf::Color& textColor               = sf::Color::Black,
                                  const sf::Color& selectedBackgroundColor = sf::Color(50, 100, 200),
                                  const sf::Color& selectedTextColor       = sf::Color::White,
                                  const sf::Color& borderColor             = sf::Color::Black);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the background color that will be used inside the combo box.
        ///
        /// \see changeColors
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBackgroundColor(const sf::Color& backgroundColor);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the text color that will be used inside the combo box.
        ///
        /// \see changeColors
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTextColor(const sf::Color& textColor);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the background color of the selected text that will be used inside the combo box.
        ///
        /// \see changeColors
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSelectedBackgroundColor(const sf::Color& selectedBackgroundColor);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the text color of the selected text that will be used inside the combo box.
        ///
        /// \see changeColors
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSelectedTextColor(const sf::Color& selectedTextColor);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Set the border color text that will be used inside the combo box.
        ///
        /// \see changeColors
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorderColor(const sf::Color& borderColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the background color that is currently being used inside the combo box.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getBackgroundColor() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the text color that is currently being used inside the combo box.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getTextColor() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the background color of the selected text that is currently being used inside the combo box.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getSelectedBackgroundColor() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the text color of the selected text that is currently being used inside the combo box.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getSelectedTextColor() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the border color that is currently being used inside the combo box.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the text font.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTextFont(const sf::Font& font);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the text font.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Font* getTextFont() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the borders.
        ///
        /// \param leftBorder    The width of the left border
        /// \param topBorder     The height of the top border
        /// \param rightBorder   The width of the right border
        /// \param bottomBorder  The height of the bottom border
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorders(const unsigned int leftBorder   = 0,
                                const unsigned int topBorder    = 0,
                                const unsigned int rightBorder  = 0,
                                const unsigned int bottomBorder = 0);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Adds an item to the list, so that it can be selected later.
        ///
        /// \param itemName The name of the item you want to add (this is the text that will be displayed inside the combo box)
        ///
        /// \return
        ///         - 0 when the combo box wasn't loaded correctly
        ///         - 0 when the list is full (you have set a maximum item limit and you are trying to add more items)
        ///         - 0 when there is no scrollbar and you try to have more items than the number of items to display
        ///         - The id of the item when it was successfully added.
        ///
        /// \warning The id returned by this function is no longer correct when an item is removed. Use it immediately or don't use it at all.
        ///
        /// \see setMaximumItems
        /// \see setItemsToDisplay
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int addItem(const sf::String itemName);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Selects an item from the list.
        ///
        /// When adding items to the combo box with the addItem function, none of them will be selected.
        /// If you don't want the combo box to stay empty until the user selects something, but you want a default item instead,
        /// then you can use this function to select an item.
        /// The first item that matches the name will be selected.
        ///
        /// \return
        ///         - true on success
        ///         - false when none of the items matches the name
        ///
        /// \see setSelectedItem(unsigned int)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setSelectedItem(const sf::String itemName);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Selects an item from the list.
        ///
        /// When adding items to the combo box with the addItem function, none of them will be selected.
        /// If you don't want the combo box to stay empty until the user selects something, but you want a default item instead,
        /// then you can use this function to select an item.
        ///
        /// The id starts counting from 1. If you pass 0 to this function then none of the items will be selected.
        ///
        /// \return
        ///         - true on success
        ///         - false when the id was too high
        ///
        /// \see setSelectedItem(sf::String)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setSelectedItem(const unsigned int id);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes an item from the list with a given id.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeItem(const unsigned int id);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes all items from the list with a given name.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeItem(const sf::String itemName);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes all items from the list.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeAllItems();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the item name of the given id.
        ///
        /// The string will be empty when the id was too high or when it was 0.
        ///
        /// \see getItemID
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::String getItem(const unsigned int id) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the id of the first item with the given name.
        ///
        /// If none of the items matches then the id will be 0.
        ///
        /// \warning This id is no longer correct when an item is removed. Use it immediately or don't use it at all.
        ///
        /// \see getItem
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getItemID(const sf::String itemName) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the list that constains all the items.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::vector<sf::String>& getItems() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the currently selected item.
        ///
        /// When no item was selected then this function will return an empty string.
        ///
        /// \see getSelectedItemID
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::String getSelectedItem() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Get the id of the selected item.
        ///
        /// When no item was selected then this function returns 0.
        ///
        /// \warning This id will become wrong when an item is removed from the list. Use it immediately or don't use it at all.
        ///
        /// \see getSelectedItem
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getSelectedItemID() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the scrollbar that is displayed next to the list.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setScrollbar(const std::string scrollbarPathname);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Removes the scrollbar.
        ///
        /// When there are too many items to fit in the list then the items will be removed.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void removeScrollbar();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the maximum items that the combo box can contain.
        ///
        /// If \a maximumItems is 0 then there is no limit.
        /// If no scrollbar was loaded then the amount of items that are displayed is already a limit.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setMaximumItems(const unsigned int maximumItems = 0);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the maximum items that the combo box can contain.
        ///
        /// If this function returns 0 then there is no limit.
        /// If no scrollbar was loaded then the amount of items that are displayed will still be a limit.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getMaximumItems() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are used to receive callback from EventManager.
        // You normally don't need them, but you can use them to simulate an event.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y);
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Because this struct is derived from sf::Drawable, you can just call the Draw function from your sf::RenderTarget.
        // This function will be called and it will draw the object on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Scaling is not working in ListBox yet and may thus not be used.
        ///
        /// \see setSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScale(float factorX, float factorY);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Scaling is not working in ListBox yet and may thus not be used.
        ///
        /// \see setSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScale(const Vector2f& factors);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Scaling is not working in ListBox yet and may thus not be used.
        ///
        /// \see setSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void scale(float factorX, float factorY);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Scaling is not working in ListBox yet and may thus not be used.
        ///
        /// \see setSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void scale(const Vector2f& factor);

        // Group must be able to access the scale
        friend struct Group;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        // This boolean becomes true when you clicked on the combo box, when the list should be shown
        bool m_ShowList;

        // When the mouse is on top of the object, it might be on the list box part.
        bool m_MouseOnListBox;

        // The number of items to display. If there is a scrollbar then you can scroll to see the other.
        // If there is no scrollbar then this will be the maximum amount of items.
        unsigned int m_NrOfItemsToDisplay;

        // Internally a list box is used to store all items
        ListBox*     m_ListBox;

        // The pathname of the loaded scrollbar (if there is one)
        std::string  m_LoadedScrollbarPathname;

        // The textures for the arrow image
        sf::Texture* m_TextureNormal;
        sf::Texture* m_TextureHover;

        // The sprites for the arrow image
        sf::Sprite   m_SpriteNormal;
        sf::Sprite   m_SpriteHover;

        // The pathname that was used to load the combo box
        std::string  m_LoadedPathname;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_TGUI_COMBO_BOX_INCLUDED_


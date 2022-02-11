static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
enum V_7 V_8 ;
const struct V_9 * V_10 = V_4 -> V_11 ;
F_2 ( V_4 -> V_12 == V_13 ||
V_4 -> V_12 == V_14 ) ;
V_6 = F_3 ( V_2 , & V_8 ) ;
F_2 ( V_6 && ( V_8 == V_15 || V_8 == V_16 ||
V_8 == V_17 ) ) ;
F_2 ( V_4 -> V_18 != NULL ) ;
return F_4 ( V_6 , & V_10 -> V_19 [ 0 ] , V_20 ) ;
}
static unsigned int
F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
enum V_7 V_8 ;
const struct V_9 * V_10 = V_4 -> V_11 ;
F_2 ( V_4 -> V_12 == V_21 ||
V_4 -> V_12 == V_22 ) ;
V_6 = F_3 ( V_2 , & V_8 ) ;
F_2 ( V_6 && ( V_8 == V_15 || V_8 == V_16 ) ) ;
return F_4 ( V_6 , & V_10 -> V_19 [ 0 ] , V_23 ) ;
}
static int F_6 ( const struct V_24 * V_4 )
{
const struct V_9 * V_10 = V_4 -> V_11 ;
if ( V_10 -> V_25 != 1 ) {
F_7 ( L_1 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_8 ( const struct V_24 * V_4 )
{
const struct V_9 * V_10 = V_4 -> V_11 ;
if ( V_10 -> V_25 != 1 ) {
F_7 ( L_2 ) ;
return - V_26 ;
}
return 0 ;
}
static unsigned int
F_9 ( struct V_5 * V_6 , unsigned int V_12 )
{
struct V_27 V_19 ;
V_19 . V_28 = 0 ;
F_10 ( L_3 , V_6 ,
F_11 ( V_12 ) == V_20 ?
& V_6 -> V_29 [ V_30 ] . V_31 . V_32 . V_33 . V_34 :
& V_6 -> V_29 [ V_30 ] . V_31 . V_35 . V_33 . V_34 ) ;
return F_4 ( V_6 , & V_19 , F_11 ( V_12 ) ) ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned int V_12 ,
const struct V_36 * V_37 ,
const struct V_36 * V_18 ,
struct V_5 * V_6 )
{
struct V_38 * V_38 = F_13 ( V_6 ) ;
int V_39 ;
V_39 = F_14 ( V_2 , V_12 , V_37 , V_18 , V_38 -> V_40 . V_41 ) ;
if ( V_39 == V_42 ) {
if ( ! F_15 ( V_6 , F_11 ( V_12 ) ) )
V_39 = F_9 ( V_6 , V_12 ) ;
}
return V_39 ;
}
static int T_1 F_16 ( struct V_38 * V_38 )
{
struct V_43 * V_44 ;
V_44 = F_17 ( & V_41 ) ;
if ( V_44 == NULL )
return - V_45 ;
V_38 -> V_40 . V_41 = F_18 ( V_38 , & V_41 , V_44 ) ;
F_19 ( V_44 ) ;
if ( F_20 ( V_38 -> V_40 . V_41 ) )
return F_21 ( V_38 -> V_40 . V_41 ) ;
return 0 ;
}
static void T_2 F_22 ( struct V_38 * V_38 )
{
F_23 ( V_38 , V_38 -> V_40 . V_41 ) ;
}
int T_3 F_24 ( void )
{
int V_39 ;
V_39 = F_25 ( & V_46 ) ;
if ( V_39 != 0 )
goto V_18;
V_39 = F_26 ( & V_47 ) ;
if ( V_39 != 0 )
goto V_48;
V_39 = F_26 ( & V_49 ) ;
if ( V_39 != 0 )
goto V_50;
return V_39 ;
V_50:
F_27 ( & V_47 ) ;
V_48:
F_28 ( & V_46 ) ;
V_18:
return V_39 ;
}
void F_29 ( void )
{
F_27 ( & V_49 ) ;
F_27 ( & V_47 ) ;
F_28 ( & V_46 ) ;
}

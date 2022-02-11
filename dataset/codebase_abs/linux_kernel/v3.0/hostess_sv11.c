static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
F_4 ( V_8 , V_8 -> V_9 - 2 ) ;
V_8 -> V_10 = F_5 ( V_8 , V_6 -> V_11 ) ;
F_6 ( V_8 ) ;
V_8 -> V_3 = V_6 -> V_11 ;
F_7 ( V_8 ) ;
}
static int F_8 ( struct V_2 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_12 ) ;
int V_14 = - 1 ;
switch ( V_15 ) {
case 0 :
V_14 = F_9 ( V_12 , & V_13 -> V_16 ) ;
break;
case 1 :
V_14 = F_10 ( V_12 , & V_13 -> V_16 ) ;
break;
case 2 :
V_14 = F_11 ( V_12 , & V_13 -> V_16 ) ;
break;
}
if ( V_14 )
return V_14 ;
V_14 = F_12 ( V_12 ) ;
if ( V_14 ) {
switch ( V_15 ) {
case 0 :
F_13 ( V_12 , & V_13 -> V_16 ) ;
break;
case 1 :
F_14 ( V_12 , & V_13 -> V_16 ) ;
break;
case 2 :
F_15 ( V_12 , & V_13 -> V_16 ) ;
break;
}
return V_14 ;
}
V_13 -> V_16 . V_17 = F_3 ;
F_16 ( V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_12 ) ;
V_13 -> V_16 . V_17 = V_18 ;
F_18 ( V_12 ) ;
F_19 ( V_12 ) ;
switch ( V_15 ) {
case 0 :
F_13 ( V_12 , & V_13 -> V_16 ) ;
break;
case 1 :
F_14 ( V_12 , & V_13 -> V_16 ) ;
break;
case 2 :
F_15 ( V_12 , & V_13 -> V_16 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_12 , struct V_19 * V_20 , int V_21 )
{
return F_21 ( V_12 , V_20 , V_21 ) ;
}
static T_1 F_22 ( struct V_7 * V_8 ,
struct V_2 * V_12 )
{
return F_23 ( & F_1 ( V_12 ) -> V_16 , V_8 ) ;
}
static int F_24 ( struct V_2 * V_3 , unsigned short V_22 ,
unsigned short V_23 )
{
if ( V_22 == V_24 && V_23 == V_25 )
return 0 ;
return - V_26 ;
}
static struct V_1 * F_25 ( int V_27 , int V_28 )
{
struct V_1 * V_29 ;
struct V_2 * V_30 ;
if ( ! F_26 ( V_27 , 8 , L_1 ) ) {
F_27 ( V_31 L_2 ,
V_27 ) ;
return NULL ;
}
V_29 = F_28 ( sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_29 )
goto V_33;
V_29 -> V_34 = 0 ;
V_29 -> V_16 . V_35 = V_27 + 1 ;
V_29 -> V_16 . V_36 = V_27 + 3 ;
V_29 -> V_37 . V_35 = - 1 ;
V_29 -> V_37 . V_36 = - 1 ;
V_29 -> V_16 . V_38 = & V_39 ;
V_29 -> V_37 . V_38 = & V_39 ;
F_29 ( 0 , V_27 + 4 ) ;
if ( F_30 ( V_28 , V_40 , V_41 ,
L_3 , V_29 ) < 0 ) {
F_27 ( V_31 L_4 , V_28 ) ;
goto V_42;
}
V_29 -> V_28 = V_28 ;
V_29 -> V_16 . V_43 = V_29 ;
V_29 -> V_16 . V_3 = V_29 ;
V_29 -> V_37 . V_3 = V_29 ;
if ( V_15 ) {
V_29 -> V_16 . V_44 = 3 ;
V_29 -> V_16 . V_45 = 1 ;
F_29 ( 0x03 | 0x08 , V_27 + 4 ) ;
if ( F_31 ( V_29 -> V_16 . V_44 , L_5 ) )
goto V_46;
if ( V_15 == 1 )
if ( F_31 ( V_29 -> V_16 . V_45 , L_6 ) )
goto V_47;
}
F_32 ( V_28 ) ;
if ( F_33 ( V_29 ) ) {
F_27 ( V_48 L_7 ) ;
F_34 ( V_28 ) ;
goto V_49;
}
F_35 ( & V_29 -> V_37 , V_50 ) ;
if ( V_29 -> type == V_51 )
F_35 ( & V_29 -> V_16 , V_52 ) ;
else
F_35 ( & V_29 -> V_16 , V_53 ) ;
F_34 ( V_28 ) ;
V_29 -> V_16 . V_11 = V_30 = F_36 ( V_29 ) ;
if ( ! V_30 )
goto V_49;
F_2 ( V_30 ) -> V_54 = F_24 ;
F_2 ( V_30 ) -> V_55 = F_22 ;
V_30 -> V_56 = & V_57 ;
V_30 -> V_58 = V_27 ;
V_30 -> V_28 = V_28 ;
if ( F_37 ( V_30 ) ) {
F_27 ( V_48 L_8 ) ;
F_38 ( V_30 ) ;
goto V_49;
}
F_39 ( V_29 , L_9 , V_27 ) ;
V_29 -> V_34 = 1 ;
return V_29 ;
V_49:
if ( V_15 == 1 )
V_49 ( V_29 -> V_16 . V_45 ) ;
V_47:
if ( V_15 )
V_49 ( V_29 -> V_16 . V_44 ) ;
V_46:
F_40 ( V_28 , V_29 ) ;
V_42:
F_41 ( V_29 ) ;
V_33:
F_42 ( V_27 , 8 ) ;
return NULL ;
}
static void F_43 ( struct V_1 * V_3 )
{
F_44 ( V_3 -> V_16 . V_11 ) ;
F_45 ( V_3 ) ;
F_40 ( V_3 -> V_28 , V_3 ) ;
if ( V_15 ) {
if ( V_15 == 1 )
V_49 ( V_3 -> V_16 . V_45 ) ;
V_49 ( V_3 -> V_16 . V_44 ) ;
}
F_42 ( V_3 -> V_16 . V_35 - 1 , 8 ) ;
F_38 ( V_3 -> V_16 . V_11 ) ;
F_41 ( V_3 ) ;
}
int F_46 ( void )
{
if ( ( V_59 = F_25 ( V_60 , V_28 ) ) == NULL )
return - V_61 ;
return 0 ;
}
void F_47 ( void )
{
if ( V_59 )
F_43 ( V_59 ) ;
}

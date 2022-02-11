static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_2 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_5 && V_5 -> V_9 )
return V_5 -> V_9 ( V_2 ) ;
else
return - V_10 ;
}
static int F_3 ( struct V_11 * V_12 )
{
int V_13 = 1000 ;
while ( -- V_13 && ! ( F_4 ( V_12 , V_14 ) & ( 1 << 13 ) ) )
F_5 ( 1 ) ;
if ( ! V_13 ) {
F_6 ( V_12 -> V_15 -> V_6 , L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_11 * V_12 , int V_17 )
{
switch ( V_17 )
{
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return F_3 ( V_12 ) ;
}
return 0 ;
}
static int T_1 F_8 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_11 * V_12 ;
char V_30 [ 8 ] ;
int V_31 , V_32 , V_33 ;
V_27 = F_9 ( sizeof( struct V_26 ) , V_34 ) ;
if ( V_27 == NULL ) {
F_10 ( & V_2 -> V_6 , L_2 ) ;
return - V_35 ;
}
V_29 = & V_27 -> V_29 ;
V_5 -> V_15 = V_29 ;
snprintf ( V_30 , sizeof( V_30 ) , L_3 , V_2 -> V_36 ) ;
V_27 -> V_37 = F_11 ( & V_2 -> V_6 , V_30 ) ;
if ( F_12 ( V_27 -> V_37 ) ) {
F_10 ( & V_2 -> V_6 , L_4 , V_30 ) ;
V_33 = F_13 ( V_27 -> V_37 ) ;
goto V_38;
}
F_14 ( V_27 -> V_37 ) ;
V_29 -> V_39 = F_15 ( V_27 -> V_37 ) ;
V_29 -> V_8 = F_1 ;
V_29 -> V_9 = F_2 ;
V_29 -> V_40 = V_41 ;
if ( V_5 ) {
V_29 -> V_42 = V_5 -> V_43 ;
if ( V_29 -> V_42 & V_44 )
V_29 -> V_45 = F_7 ;
V_29 -> V_46 = V_5 -> V_47 ;
V_29 -> V_40 |= V_5 -> V_48 ;
if ( V_5 -> V_49 > 0 && V_5 -> V_50 > 0 ) {
V_27 -> V_51 . V_52 = V_5 -> V_49 ;
V_27 -> V_53 . V_52 = V_5 -> V_50 ;
V_27 -> V_54 . V_55 = & V_27 -> V_51 ;
V_27 -> V_54 . V_56 = & V_27 -> V_53 ;
V_27 -> V_54 . V_57 = 1 ;
V_29 -> V_58 = & V_27 -> V_54 ;
}
}
V_29 -> V_42 |= V_59 ;
V_29 -> V_42 |= V_60 ;
V_33 = F_16 ( & V_12 , V_2 , V_29 ) ;
if ( V_33 < 0 )
goto V_61;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_32 = F_17 ( V_2 , V_31 ) ;
if ( V_32 < 0 ) {
if ( V_31 ) {
continue;
} else {
V_33 = V_32 ;
goto V_62;
}
}
V_33 = F_18 ( V_32 , V_63 , 0 ,
F_19 ( & V_2 -> V_6 ) , V_12 ) ;
if ( V_33 ) {
while ( V_31 -- ) {
V_32 = F_17 ( V_2 , V_31 ) ;
if ( V_32 >= 0 )
F_20 ( V_32 , V_12 ) ;
}
goto V_62;
}
}
F_21 ( & V_2 -> V_6 , L_5 ,
F_22 ( V_12 -> V_64 ) , ( unsigned long )
( F_23 ( V_2 , V_65 , 0 ) -> V_66 ) ,
V_29 -> V_39 / 1000000 ) ;
return V_33 ;
V_62:
F_24 ( V_12 ) ;
V_61:
F_25 ( V_27 -> V_37 ) ;
F_26 ( V_27 -> V_37 ) ;
V_38:
F_27 ( V_27 ) ;
return V_33 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_67 * V_64 = F_29 ( V_2 ) ;
struct V_11 * V_12 = F_30 ( V_64 ) ;
struct V_26 * V_27 = F_31 ( V_12 -> V_15 , struct V_26 , V_29 ) ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
int V_31 , V_32 ;
V_5 -> V_15 = NULL ;
F_24 ( V_12 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_32 = F_17 ( V_2 , V_31 ) ;
if ( V_32 >= 0 )
F_20 ( V_32 , V_12 ) ;
}
F_25 ( V_27 -> V_37 ) ;
F_26 ( V_27 -> V_37 ) ;
F_27 ( V_27 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_68 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_68 ) ;
}

static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
unsigned long V_6 ;
* V_5 = F_2 ( V_2 -> V_7 . V_8 + V_9 ) ;
if ( ( * V_5 & V_3 ) == V_4 )
return 0 ;
V_6 = V_10 + 10 * V_11 ;
do {
F_3 ( V_12 ) ;
* V_5 = F_2 ( V_2 -> V_7 . V_8 + 1 ) ;
if ( ( * V_5 & V_3 ) == V_4 )
return 0 ;
}
while ( F_4 ( V_10 , V_6 ) );
return - V_13 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_14 ;
unsigned long V_6 ;
V_14 = F_2 ( V_2 -> V_7 . V_8 + V_9 ) ;
if ( V_14 & V_15 )
V_14 = F_2 ( V_2 -> V_7 . V_8 + V_16 ) ;
if ( V_14 & V_17 )
return 0 ;
V_6 = V_10 + 100 ;
do {
F_3 ( V_12 ) ;
V_14 = F_2 ( V_2 -> V_7 . V_8 + V_9 ) ;
if ( V_14 & V_15 )
V_14 = F_2 ( V_2 -> V_7 . V_8 + V_16 ) ;
if ( V_14 & V_17 )
return 0 ;
}
while ( F_4 ( V_10 , V_6 ) );
F_6 ( V_2 -> V_18 , L_1 ) ;
return - V_13 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_19 , T_2 V_20 )
{
T_1 * V_21 = V_19 ;
T_1 V_5 , * V_22 ;
T_3 V_23 ;
T_4 * V_24 ;
if ( V_20 < 6 )
return - V_25 ;
if ( F_1 ( V_2 , V_26 , V_26 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 , L_2 ) ;
return - V_25 ;
}
if ( ( V_5 =
F_2 ( V_2 -> V_7 . V_8 + V_16 ) ) != V_27 ) {
F_8 ( V_2 -> V_18 , L_3 ,
V_5 ) ;
return - V_25 ;
}
for ( V_22 = V_21 ; V_22 < & V_21 [ V_20 ] ; V_22 ++ ) {
if ( F_1
( V_2 , V_15 , V_15 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 ,
L_4 ) ;
return - V_25 ;
}
if ( V_5 & V_26 )
break;
* V_22 = F_2 ( V_2 -> V_7 . V_8 + V_16 ) ;
}
if ( ( V_5 & V_26 ) == 0 &&
( F_1 ( V_2 , V_26 , V_26 , & V_5 ) < 0 ) ) {
F_8 ( V_2 -> V_18 , L_5 ) ;
return - V_25 ;
}
if ( ( V_5 = F_2 ( V_2 -> V_7 . V_8 + V_16 ) ) != V_28 ) {
F_8 ( V_2 -> V_18 ,
L_6 , V_5 ) ;
return - V_25 ;
}
V_24 = ( V_29 T_4 * ) ( V_19 + 2 ) ;
V_23 = F_9 ( * V_24 ) ;
if ( V_20 < V_23 )
return - V_25 ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_19 , T_2 V_20 )
{
T_1 V_5 ;
int V_30 ;
F_11 ( V_31 , V_2 -> V_7 . V_8 + V_32 ) ;
if ( F_5 ( V_2 ) != 0 )
return - V_25 ;
if ( F_1 ( V_2 , V_33 , 0 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 , L_7 ) ;
return - V_25 ;
}
F_11 ( V_27 , V_2 -> V_7 . V_8 + V_32 ) ;
if ( F_1 ( V_2 , V_34 , V_34 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 , L_8 ) ;
return - V_25 ;
}
for ( V_30 = 0 ; V_30 < V_20 ; V_30 ++ ) {
if ( F_1 ( V_2 , V_33 , 0 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 ,
L_9 ) ;
return - V_25 ;
}
F_11 ( V_19 [ V_30 ] , V_2 -> V_7 . V_8 + V_16 ) ;
}
if ( F_1 ( V_2 , V_33 , 0 , & V_5 ) < 0 ) {
F_8 ( V_2 -> V_18 , L_7 ) ;
return - V_25 ;
}
F_11 ( V_28 , V_2 -> V_7 . V_8 + V_32 ) ;
return V_20 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_31 , V_2 -> V_7 . V_8 + V_32 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_7 . V_8 + V_9 ) ;
}
static void F_14 ( struct V_35 * V_18 )
{
struct V_1 * V_2 = F_15 ( V_18 ) ;
if ( V_2 ) {
F_16 ( V_2 -> V_7 . V_8 , 2 ) ;
F_17 ( V_2 -> V_18 ) ;
}
}
static int F_18 ( struct V_36 * V_18 , T_5 V_37 )
{
return F_19 ( & V_18 -> V_18 , V_37 ) ;
}
static int F_20 ( struct V_36 * V_18 )
{
return F_21 ( & V_18 -> V_18 ) ;
}
static int T_6 F_22 ( void )
{
int V_38 = 0 ;
int V_39 , V_40 , V_41 ;
int V_42 = V_43 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( F_23 ( V_43 , V_44 ) != 0xEF ) {
V_42 = ( F_23 ( V_45 , 0x2C ) << 8 ) |
( F_23 ( V_45 , 0x2B ) & 0xFE ) ;
if ( F_23 ( V_42 , V_44 ) != 0xF6 )
return - V_46 ;
}
V_41 = F_24 ( & V_47 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_23 ( V_42 , V_48 ) ;
V_39 = F_23 ( V_42 , V_49 ) ;
V_8 = ( V_40 << 8 ) | V_39 ;
F_25 ( V_42 , V_50 , 0x01 ) ;
V_51 = F_26 ( L_10 , - 1 ) ;
if ( ! V_51 ) {
V_38 = - V_52 ;
goto V_53;
}
V_51 -> V_54 = 0 ;
V_51 -> V_18 . V_55 = & V_47 . V_55 ;
V_51 -> V_18 . V_56 = F_14 ;
if ( ( V_38 = F_27 ( V_51 ) ) < 0 )
goto V_57;
if ( F_28 ( V_8 , 2 , L_11 ) == NULL ) {
V_38 = - V_13 ;
goto V_58;
}
if ( ! ( V_2 = F_29 ( & V_51 -> V_18 , & V_59 ) ) ) {
V_38 = - V_46 ;
goto V_60;
}
F_30 ( & V_51 -> V_18 , L_12 ) ;
F_30 ( & V_51 -> V_18 ,
L_13 ,
F_23 ( V_42 , 0x07 ) , F_23 ( V_42 , 0x20 ) ,
F_23 ( V_42 , 0x27 ) ) ;
F_30 ( & V_51 -> V_18 ,
L_14 ,
F_23 ( V_42 , 0x21 ) , F_23 ( V_42 , 0x25 ) ,
F_23 ( V_42 , 0x26 ) , F_23 ( V_42 , 0x28 ) ) ;
F_30 ( & V_51 -> V_18 , L_15 ,
( F_23 ( V_42 , 0x60 ) << 8 ) | F_23 ( V_42 , 0x61 ) ) ;
F_30 ( & V_51 -> V_18 , L_16 ,
( F_23 ( V_42 , 0x62 ) << 8 ) | F_23 ( V_42 , 0x63 ) ) ;
F_30 ( & V_51 -> V_18 , L_17 ,
F_23 ( V_42 , 0x70 ) ) ;
F_30 ( & V_51 -> V_18 , L_18 ,
F_23 ( V_42 , 0x71 ) ) ;
F_30 ( & V_51 -> V_18 ,
L_19 ,
F_23 ( V_42 , 0x74 ) , F_23 ( V_42 , 0x75 ) ) ;
F_30 ( & V_51 -> V_18 ,
L_20
L_21 ,
F_23 ( V_42 , 0xF0 ) , F_23 ( V_42 , 0xF1 ) ,
F_23 ( V_42 , 0xF2 ) , F_23 ( V_42 , 0xF3 ) ,
F_23 ( V_42 , 0xF4 ) , F_23 ( V_42 , 0xF5 ) ,
F_23 ( V_42 , 0xF6 ) , F_23 ( V_42 , 0xF7 ) ,
F_23 ( V_42 , 0xF8 ) , F_23 ( V_42 , 0xF9 ) ) ;
F_6 ( & V_51 -> V_18 ,
L_22 ,
F_23 ( V_42 , 0x27 ) & 0x1F ) ;
V_2 -> V_7 . V_8 = V_8 ;
return 0 ;
V_60:
F_16 ( V_8 , 2 ) ;
V_58:
F_31 ( V_51 ) ;
V_57:
F_32 ( V_51 ) ;
V_53:
F_33 ( & V_47 ) ;
return V_38 ;
}
static void T_7 F_34 ( void )
{
if ( V_51 ) {
F_14 ( & V_51 -> V_18 ) ;
F_31 ( V_51 ) ;
F_32 ( V_51 ) ;
V_51 = NULL ;
}
F_33 ( & V_47 ) ;
}

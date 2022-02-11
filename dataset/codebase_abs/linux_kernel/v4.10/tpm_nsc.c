static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
unsigned long V_9 ;
* V_5 = F_3 ( V_7 -> V_10 + V_11 ) ;
if ( ( * V_5 & V_3 ) == V_4 )
return 0 ;
V_9 = V_12 + 10 * V_13 ;
do {
F_4 ( V_14 ) ;
* V_5 = F_3 ( V_7 -> V_10 + 1 ) ;
if ( ( * V_5 & V_3 ) == V_4 )
return 0 ;
}
while ( F_5 ( V_12 , V_9 ) );
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_16 ;
unsigned long V_9 ;
V_16 = F_3 ( V_7 -> V_10 + V_11 ) ;
if ( V_16 & V_17 )
V_16 = F_3 ( V_7 -> V_10 + V_18 ) ;
if ( V_16 & V_19 )
return 0 ;
V_9 = V_12 + 100 ;
do {
F_4 ( V_14 ) ;
V_16 = F_3 ( V_7 -> V_10 + V_11 ) ;
if ( V_16 & V_17 )
V_16 = F_3 ( V_7 -> V_10 + V_18 ) ;
if ( V_16 & V_19 )
return 0 ;
}
while ( F_5 ( V_12 , V_9 ) );
F_7 ( & V_2 -> V_8 , L_1 ) ;
return - V_15 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_20 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
T_1 * V_22 = V_20 ;
T_1 V_5 , * V_23 ;
T_3 V_24 ;
T_4 * V_25 ;
if ( V_21 < 6 )
return - V_26 ;
if ( F_1 ( V_2 , V_27 , V_27 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 , L_2 ) ;
return - V_26 ;
}
V_5 = F_3 ( V_7 -> V_10 + V_18 ) ;
if ( V_5 != V_28 ) {
F_9 ( & V_2 -> V_8 , L_3 ,
V_5 ) ;
return - V_26 ;
}
for ( V_23 = V_22 ; V_23 < & V_22 [ V_21 ] ; V_23 ++ ) {
if ( F_1
( V_2 , V_17 , V_17 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 ,
L_4 ) ;
return - V_26 ;
}
if ( V_5 & V_27 )
break;
* V_23 = F_3 ( V_7 -> V_10 + V_18 ) ;
}
if ( ( V_5 & V_27 ) == 0 &&
( F_1 ( V_2 , V_27 , V_27 , & V_5 ) < 0 ) ) {
F_9 ( & V_2 -> V_8 , L_5 ) ;
return - V_26 ;
}
V_5 = F_3 ( V_7 -> V_10 + V_18 ) ;
if ( V_5 != V_29 ) {
F_9 ( & V_2 -> V_8 ,
L_6 , V_5 ) ;
return - V_26 ;
}
V_25 = ( V_30 T_4 * ) ( V_20 + 2 ) ;
V_24 = F_10 ( * V_25 ) ;
if ( V_21 < V_24 )
return - V_26 ;
return V_24 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_20 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
T_1 V_5 ;
int V_31 ;
F_12 ( V_32 , V_7 -> V_10 + V_33 ) ;
if ( F_6 ( V_2 ) != 0 )
return - V_26 ;
if ( F_1 ( V_2 , V_34 , 0 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 , L_7 ) ;
return - V_26 ;
}
F_12 ( V_28 , V_7 -> V_10 + V_33 ) ;
if ( F_1 ( V_2 , V_35 , V_35 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 , L_8 ) ;
return - V_26 ;
}
for ( V_31 = 0 ; V_31 < V_21 ; V_31 ++ ) {
if ( F_1 ( V_2 , V_34 , 0 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 ,
L_9 ) ;
return - V_26 ;
}
F_12 ( V_20 [ V_31 ] , V_7 -> V_10 + V_18 ) ;
}
if ( F_1 ( V_2 , V_34 , 0 , & V_5 ) < 0 ) {
F_9 ( & V_2 -> V_8 , L_7 ) ;
return - V_26 ;
}
F_12 ( V_29 , V_7 -> V_10 + V_33 ) ;
return V_21 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_12 ( V_32 , V_7 -> V_10 + V_33 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
return F_3 ( V_7 -> V_10 + V_11 ) ;
}
static bool F_15 ( struct V_1 * V_2 , T_1 V_16 )
{
return ( V_16 == V_19 ) ;
}
static void F_16 ( struct V_36 * V_8 )
{
struct V_1 * V_2 = F_2 ( V_8 ) ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_17 ( V_2 ) ;
F_18 ( V_7 -> V_10 , 2 ) ;
}
static int T_5 F_19 ( void )
{
int V_37 = 0 ;
int V_38 , V_39 , V_40 ;
int V_41 = V_42 ;
struct V_1 * V_2 ;
unsigned long V_10 ;
struct V_6 * V_7 ;
if ( F_20 ( V_42 , V_43 ) != 0xEF ) {
V_41 = ( F_20 ( V_44 , 0x2C ) << 8 ) |
( F_20 ( V_44 , 0x2B ) & 0xFE ) ;
if ( F_20 ( V_41 , V_43 ) != 0xF6 )
return - V_45 ;
}
V_40 = F_21 ( & V_46 ) ;
if ( V_40 )
return V_40 ;
V_39 = F_20 ( V_41 , V_47 ) ;
V_38 = F_20 ( V_41 , V_48 ) ;
V_10 = ( V_39 << 8 ) | V_38 ;
F_22 ( V_41 , V_49 , 0x01 ) ;
V_50 = F_23 ( L_10 , - 1 ) ;
if ( ! V_50 ) {
V_37 = - V_51 ;
goto V_52;
}
V_50 -> V_53 = 0 ;
V_50 -> V_8 . V_54 = & V_46 . V_54 ;
V_50 -> V_8 . V_55 = F_16 ;
if ( ( V_37 = F_24 ( V_50 ) ) < 0 )
goto V_56;
V_7 = F_25 ( & V_50 -> V_8 , sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
V_37 = - V_51 ;
goto V_58;
}
V_7 -> V_10 = V_10 ;
if ( F_26 ( V_10 , 2 , L_11 ) == NULL ) {
V_37 = - V_15 ;
goto V_58;
}
V_2 = F_27 ( & V_50 -> V_8 , & V_59 ) ;
if ( F_28 ( V_2 ) ) {
V_37 = - V_45 ;
goto V_60;
}
F_29 ( & V_2 -> V_8 , V_7 ) ;
V_37 = F_30 ( V_2 ) ;
if ( V_37 )
goto V_60;
F_31 ( & V_50 -> V_8 , L_12 ) ;
F_31 ( & V_50 -> V_8 ,
L_13 ,
F_20 ( V_41 , 0x07 ) , F_20 ( V_41 , 0x20 ) ,
F_20 ( V_41 , 0x27 ) ) ;
F_31 ( & V_50 -> V_8 ,
L_14 ,
F_20 ( V_41 , 0x21 ) , F_20 ( V_41 , 0x25 ) ,
F_20 ( V_41 , 0x26 ) , F_20 ( V_41 , 0x28 ) ) ;
F_31 ( & V_50 -> V_8 , L_15 ,
( F_20 ( V_41 , 0x60 ) << 8 ) | F_20 ( V_41 , 0x61 ) ) ;
F_31 ( & V_50 -> V_8 , L_16 ,
( F_20 ( V_41 , 0x62 ) << 8 ) | F_20 ( V_41 , 0x63 ) ) ;
F_31 ( & V_50 -> V_8 , L_17 ,
F_20 ( V_41 , 0x70 ) ) ;
F_31 ( & V_50 -> V_8 , L_18 ,
F_20 ( V_41 , 0x71 ) ) ;
F_31 ( & V_50 -> V_8 ,
L_19 ,
F_20 ( V_41 , 0x74 ) , F_20 ( V_41 , 0x75 ) ) ;
F_31 ( & V_50 -> V_8 ,
L_20
L_21 ,
F_20 ( V_41 , 0xF0 ) , F_20 ( V_41 , 0xF1 ) ,
F_20 ( V_41 , 0xF2 ) , F_20 ( V_41 , 0xF3 ) ,
F_20 ( V_41 , 0xF4 ) , F_20 ( V_41 , 0xF5 ) ,
F_20 ( V_41 , 0xF6 ) , F_20 ( V_41 , 0xF7 ) ,
F_20 ( V_41 , 0xF8 ) , F_20 ( V_41 , 0xF9 ) ) ;
F_7 ( & V_50 -> V_8 ,
L_22 ,
F_20 ( V_41 , 0x27 ) & 0x1F ) ;
return 0 ;
V_60:
F_18 ( V_10 , 2 ) ;
V_58:
F_32 ( V_50 ) ;
V_56:
F_33 ( V_50 ) ;
V_52:
F_34 ( & V_46 ) ;
return V_37 ;
}
static void T_6 F_35 ( void )
{
if ( V_50 ) {
F_16 ( & V_50 -> V_8 ) ;
F_36 ( V_50 ) ;
}
F_34 ( & V_46 ) ;
}

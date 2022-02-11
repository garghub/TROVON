static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 =
F_2 ( V_2 -> V_7 , V_8 , 0x08 ,
V_6 -> V_9 ) ;
if ( V_3 < 0 )
goto V_10;
V_4 = ( V_6 -> V_9 & 0x40 ) | V_6 -> V_11 | V_6 -> V_12 ;
V_3 = F_2 ( V_2 -> V_7 , V_13 , 0x7C , V_4 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_3 ( V_2 -> V_7 , V_14 , V_6 -> V_15 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_3 ( V_2 -> V_7 , V_16 , V_6 -> V_15 ) ;
if ( V_3 < 0 )
goto V_10;
if ( ! V_6 -> V_15 ) {
V_4 = V_6 -> V_17 ;
V_4 |= V_6 -> V_18 ;
} else {
V_4 = V_6 -> V_17 ;
V_4 |= V_6 -> V_18 | 0x01 ;
}
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x79 , V_4 ) ;
if ( V_3 < 0 )
goto V_10;
return V_3 ;
V_10:
F_4 ( V_2 -> V_20 , L_1 ) ;
return V_3 ;
}
static int F_5 ( struct V_21 * V_22 )
{
int V_3 ;
unsigned int V_4 ;
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 = F_7 ( V_2 -> V_7 , V_23 , & V_4 ) ;
if ( V_3 < 0 )
goto V_10;
if ( V_4 != 0 )
F_8 ( V_2 -> V_20 , L_2 , V_4 ) ;
if ( V_6 -> V_9 ) {
if ( V_6 -> V_24 )
V_6 -> V_24 ( V_22 -> V_25 . V_26 ,
V_6 -> V_27 ) ;
else
F_4 ( V_2 -> V_20 ,
L_3 ) ;
return V_22 -> V_25 . V_26 ;
}
V_3 = F_3 ( V_2 -> V_7 , V_14 , V_22 -> V_25 . V_26 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_3 ( V_2 -> V_7 , V_16 , V_22 -> V_25 . V_26 ) ;
if ( V_3 < 0 )
goto V_10;
if ( ! V_22 -> V_25 . V_26 )
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x01 , 0x00 ) ;
else
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x01 , 0x01 ) ;
if ( V_3 < 0 )
goto V_10;
return V_22 -> V_25 . V_26 ;
V_10:
F_4 ( V_2 -> V_20 , L_4 ) ;
return V_22 -> V_25 . V_26 ;
}
static int F_9 ( struct V_21 * V_22 )
{
int V_3 ;
unsigned int V_4 ;
struct V_1 * V_2 = F_6 ( V_22 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_9 ) {
if ( V_6 -> V_28 )
V_22 -> V_25 . V_26 = V_6 -> V_28 () ;
else
F_4 ( V_2 -> V_20 ,
L_3 ) ;
return V_22 -> V_25 . V_26 ;
}
V_3 = F_7 ( V_2 -> V_7 , V_8 , & V_4 ) ;
if ( V_3 < 0 )
goto V_10;
if ( V_4 & 0x10 )
V_3 = F_7 ( V_2 -> V_7 , V_14 , & V_4 ) ;
else
V_3 = F_7 ( V_2 -> V_7 , V_16 , & V_4 ) ;
if ( V_3 < 0 )
goto V_10;
V_22 -> V_25 . V_26 = V_4 ;
return V_22 -> V_25 . V_26 ;
V_10:
F_4 ( V_2 -> V_20 , L_1 ) ;
return V_22 -> V_25 . V_26 ;
}
static T_1 F_10 ( struct V_29 * V_20 ,
struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
unsigned int V_34 ;
V_3 = F_12 ( V_32 , 10 , & V_34 ) ;
if ( V_3 )
goto V_35;
if ( ! V_34 )
V_3 =
F_2 ( V_2 -> V_7 , V_8 , 0x10 ,
0x00 ) ;
else
V_3 =
F_2 ( V_2 -> V_7 , V_8 , 0x10 ,
0x10 ) ;
if ( V_3 < 0 )
goto V_10;
return V_33 ;
V_10:
F_4 ( V_2 -> V_20 , L_5 , V_36 ) ;
return V_3 ;
V_35:
F_4 ( V_2 -> V_20 , L_6 , V_36 ) ;
return V_3 ;
}
static void F_13 ( struct V_37 * V_38 ,
enum V_39 V_26 )
{
int V_3 ;
unsigned int V_4 ;
struct V_1 * V_2 ;
V_2 = F_14 ( V_38 , struct V_1 , V_40 ) ;
V_3 = F_7 ( V_2 -> V_7 , V_23 , & V_4 ) ;
if ( V_3 < 0 )
goto V_10;
if ( V_4 != 0 )
F_8 ( V_2 -> V_20 , L_2 , V_4 ) ;
if ( ! V_26 ) {
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x06 , 0x00 ) ;
if ( V_3 < 0 )
goto V_10;
return;
}
V_3 = F_2 ( V_2 -> V_7 ,
V_41 , 0x70 , ( V_26 - 1 ) << 4 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x06 , 0x02 ) ;
if ( V_3 < 0 )
goto V_10;
return;
V_10:
F_4 ( V_2 -> V_20 , L_1 ) ;
}
static void F_15 ( struct V_37 * V_38 ,
enum V_39 V_26 )
{
int V_3 ;
unsigned int V_4 ;
struct V_1 * V_2 ;
V_2 = F_14 ( V_38 , struct V_1 , V_42 ) ;
V_3 = F_7 ( V_2 -> V_7 , V_23 , & V_4 ) ;
if ( V_3 < 0 )
goto V_10;
if ( V_4 != 0 )
F_8 ( V_2 -> V_20 , L_2 , V_4 ) ;
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x06 , 0x00 ) ;
if ( V_3 < 0 )
goto V_10;
if ( ! V_26 )
return;
V_3 = F_2 ( V_2 -> V_7 ,
V_41 , 0x0F , V_26 - 1 ) ;
if ( V_3 < 0 )
goto V_10;
V_3 = F_2 ( V_2 -> V_7 , V_19 , 0x06 , 0x06 ) ;
if ( V_3 < 0 )
goto V_10;
return;
V_10:
F_4 ( V_2 -> V_20 , L_1 ) ;
}
static int F_16 ( struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
int V_3 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = F_17 ( & V_44 -> V_20 ) ;
struct V_47 V_25 ;
if ( ! F_18 ( V_44 -> V_48 , V_49 ) ) {
F_4 ( & V_44 -> V_20 , L_7 ) ;
return - V_50 ;
}
if ( V_6 == NULL ) {
F_4 ( & V_44 -> V_20 , L_8 ) ;
return - V_51 ;
}
V_2 = F_19 ( & V_44 -> V_20 ,
sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_20 = & V_44 -> V_20 ;
V_2 -> V_7 = F_20 ( V_44 , & V_54 ) ;
if ( F_21 ( V_2 -> V_7 ) ) {
V_3 = F_22 ( V_2 -> V_7 ) ;
F_4 ( & V_44 -> V_20 , L_9 ,
V_3 ) ;
return V_3 ;
}
F_23 ( V_44 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_44 -> V_20 , L_10 ) ;
goto V_55;
}
V_25 . type = V_56 ;
V_25 . V_26 = V_6 -> V_15 ;
V_25 . V_57 = V_6 -> V_27 ;
V_2 -> V_58 =
F_24 ( V_2 -> V_20 , L_11 ,
V_2 -> V_20 , V_2 , & V_59 ,
& V_25 ) ;
if ( F_21 ( V_2 -> V_58 ) ) {
F_4 ( & V_44 -> V_20 , L_12 ) ;
V_3 = F_22 ( V_2 -> V_58 ) ;
goto V_55;
}
V_3 = F_25 ( & ( V_2 -> V_58 -> V_20 ) , & V_60 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_44 -> V_20 , L_13 ) ;
goto V_55;
}
V_2 -> V_42 . V_61 = L_14 ;
V_2 -> V_42 . V_57 = 16 ;
V_2 -> V_42 . V_62 = F_15 ;
V_3 = F_26 ( (struct V_29 * )
& V_44 -> V_20 , & V_2 -> V_42 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_44 -> V_20 , L_15 ) ;
goto V_63;
}
V_2 -> V_40 . V_61 = L_16 ;
V_2 -> V_40 . V_57 = 8 ;
V_2 -> V_40 . V_62 = F_13 ;
V_3 = F_26 ( (struct V_29 * )
& V_44 -> V_20 , & V_2 -> V_40 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_44 -> V_20 , L_17 ) ;
goto V_64;
}
return 0 ;
V_64:
F_27 ( & V_2 -> V_42 ) ;
V_63:
F_28 ( & ( V_2 -> V_58 -> V_20 ) , & V_60 ) ;
V_55:
return V_3 ;
}
static int F_29 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
F_3 ( V_2 -> V_7 , V_19 , 0x00 ) ;
if ( & V_2 -> V_40 )
F_27 ( & V_2 -> V_40 ) ;
if ( & V_2 -> V_42 )
F_27 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_58 )
F_28 ( & ( V_2 -> V_58 -> V_20 ) , & V_60 ) ;
return 0 ;
}

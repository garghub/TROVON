static T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 , int * V_4 )
{
unsigned int V_5 ;
struct V_6 T_2 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
T_1 V_11 ;
V_5 = F_2 ( V_12 ) ;
if ( V_3 && strcmp ( V_3 , L_1 ) == 0 )
* V_4 = V_13 ;
else
* V_4 = V_14 ;
V_10 = F_3 ( V_2 -> V_15 . V_16 ) ;
if ( ! V_10 )
return 0 ;
if ( * V_4 == V_13 || V_5 == 0x80822011 )
return V_10 ;
V_9 = F_4 ( NULL , V_17 ) ;
if ( ! V_9 ) {
F_5 ( & V_2 -> V_15 , L_2 ) ;
return 0 ;
}
V_7 = F_6 ( V_9 , 0 ) ;
if ( F_7 ( & V_7 -> V_18 ) & 0x1 )
V_10 *= 2 ;
V_11 = F_8 ( & V_7 -> V_19 ) ;
V_10 *= ( V_11 & ( 1 << 5 ) ) ? 8 : 4 ;
V_10 /= ( V_11 & ( 1 << 6 ) ) ? 12 : 16 ;
F_9 ( V_9 ) ;
F_10 ( V_7 ) ;
return V_10 ;
}
static T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 , int * V_4 )
{
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , int * V_4 )
{
struct V_20 T_2 * V_21 ;
struct V_8 * V_22 ;
struct V_23 * V_24 , * V_25 ;
int V_26 , V_27 , V_28 = - 1 ;
T_1 V_29 , V_11 , V_30 = 1 , V_10 = 0 ;
const T_1 * V_31 ;
V_22 = F_4 ( NULL , V_32 ) ;
if ( ! V_22 ) {
F_5 ( & V_2 -> V_15 , L_3 ) ;
return 0 ;
}
V_21 = F_6 ( V_22 , 0 ) ;
if ( ! V_21 ) {
F_5 ( & V_2 -> V_15 , L_4 ) ;
goto V_33;
}
V_31 = F_12 ( V_2 -> V_15 . V_16 , L_5 , & V_26 ) ;
F_13 ( ! V_31 || V_26 < sizeof( * V_31 ) ) ;
V_27 = ( * V_31 & 0x80 ) ? 1 : 0 ;
if ( * V_31 & 0x2000 )
V_27 += 2 ;
if ( V_3 && ! strcmp ( V_3 , L_1 ) ) {
* V_4 = V_34 ;
V_10 = F_3 ( V_2 -> V_15 . V_16 ) ;
} else {
* V_4 = V_13 ;
V_31 = F_12 ( V_2 -> V_15 . V_16 ,
L_6 , & V_26 ) ;
if ( V_31 && V_26 == sizeof( * V_31 ) )
V_30 = * V_31 ;
if ( ! V_30 )
V_30 = 1 ;
if ( ! V_3 || ! strcmp ( V_3 , L_7 ) ) {
V_24 = F_14 ( & V_2 -> V_15 , L_8 ) ;
if ( F_15 ( V_24 ) ) {
F_5 ( & V_2 -> V_15 , L_9 ) ;
goto V_35;
}
V_29 = 1000000 *
( ( F_16 ( V_24 ) + 499999 ) / 1000000 ) ;
if ( ! V_3 ) {
if ( ( V_29 % 16000000 ) == 0 ) {
V_28 = 0 ;
V_30 = V_29 / 16000000 ;
V_10 = V_29 / V_30 ;
}
} else {
V_28 = 0 ;
V_10 = V_29 / V_30 ;
}
}
if ( V_28 < 0 ) {
V_25 = F_14 ( & V_2 -> V_15 , L_10 ) ;
if ( F_15 ( V_25 ) ) {
F_5 ( & V_2 -> V_15 , L_11 ) ;
goto V_35;
}
V_28 = 1 ;
V_10 = F_16 ( V_25 ) / V_30 ;
}
}
F_17 ( & V_21 -> V_36 [ V_27 ] , 0x0 ) ;
if ( V_28 >= 0 ) {
V_11 = ( V_28 << 14 ) | ( ( V_30 - 1 ) << 17 ) ;
F_17 ( & V_21 -> V_36 [ V_27 ] , V_11 ) ;
F_17 ( & V_21 -> V_36 [ V_27 ] , V_11 | 0x10000 ) ;
}
V_11 = F_8 ( & V_21 -> V_37 [ 1 ] ) ;
if ( ! ( V_11 & ( 1 << 25 ) ) )
F_17 ( & V_21 -> V_37 [ 1 ] , V_11 | ( 1 << 25 ) ) ;
F_18 ( & V_2 -> V_15 , L_12 ,
* V_4 == V_34 ? L_13 :
V_28 == 1 ? L_10 : L_8 , V_30 ) ;
V_35:
F_10 ( V_21 ) ;
V_33:
F_9 ( V_22 ) ;
return V_10 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , int * V_4 )
{
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 ;
const struct V_40 * V_41 ;
struct V_8 * V_42 = V_2 -> V_15 . V_16 ;
struct V_43 * V_15 ;
struct V_44 * V_45 ;
void T_2 * V_46 ;
const char * V_3 = NULL ;
int V_47 , V_4 = 0 ;
int V_48 = - V_49 ;
V_39 = F_20 ( V_50 , & V_2 -> V_15 ) ;
if ( ! V_39 )
return - V_51 ;
V_41 = V_39 -> V_41 ;
V_46 = F_6 ( V_42 , 0 ) ;
if ( ! V_46 ) {
F_5 ( & V_2 -> V_15 , L_14 ) ;
return V_48 ;
}
V_47 = F_21 ( V_42 , 0 ) ;
if ( ! V_47 ) {
F_5 ( & V_2 -> V_15 , L_15 ) ;
V_48 = - V_52 ;
goto V_53;
}
V_15 = F_22 () ;
if ( ! V_15 )
goto V_54;
F_23 ( V_2 , V_15 ) ;
F_24 ( V_15 , & V_2 -> V_15 ) ;
V_45 = F_25 ( V_15 ) ;
V_45 -> V_55 = V_46 ;
V_15 -> V_47 = V_47 ;
V_3 = F_12 ( V_42 , L_16 , NULL ) ;
F_13 ( ! V_41 ) ;
V_45 -> type = V_41 -> type ;
V_45 -> V_56 . clock . V_10 = V_41 -> V_57 ( V_2 , V_3 ,
& V_4 ) ;
if ( ! V_45 -> V_56 . clock . V_10 ) {
F_5 ( & V_2 -> V_15 , L_17 ) ;
goto V_58;
}
V_48 = F_26 ( V_15 , V_4 ) ;
if ( V_48 ) {
F_5 ( & V_2 -> V_15 , L_18 ,
V_59 , V_48 ) ;
goto V_58;
}
F_27 ( & V_2 -> V_15 , L_19 ,
V_45 -> V_55 , V_15 -> V_47 , V_45 -> V_56 . clock . V_10 ) ;
return 0 ;
V_58:
F_28 ( V_15 ) ;
V_54:
F_29 ( V_47 ) ;
V_53:
F_10 ( V_46 ) ;
return V_48 ;
}
static int F_30 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 ;
const struct V_40 * V_41 ;
struct V_43 * V_15 = F_31 ( V_2 ) ;
struct V_44 * V_45 = F_25 ( V_15 ) ;
V_39 = F_20 ( V_50 , & V_2 -> V_15 ) ;
V_41 = V_39 ? V_39 -> V_41 : NULL ;
F_32 ( V_15 ) ;
if ( V_41 && V_41 -> V_60 )
V_41 -> V_60 ( V_2 ) ;
F_10 ( V_45 -> V_55 ) ;
F_29 ( V_15 -> V_47 ) ;
F_28 ( V_15 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_61 )
{
struct V_43 * V_15 = F_31 ( V_2 ) ;
struct V_44 * V_45 = F_25 ( V_15 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_45 -> V_55 ;
F_34 ( & V_64 , V_63 , sizeof( * V_63 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_15 = F_31 ( V_2 ) ;
struct V_44 * V_45 = F_25 ( V_15 ) ;
struct V_62 * V_63 = (struct V_62 * ) V_45 -> V_55 ;
V_63 -> V_65 |= V_66 ;
while ( ! ( V_63 -> V_67 & V_68 ) )
F_36 ( 10 ) ;
V_63 -> V_67 = V_64 . V_67 ;
V_63 -> V_69 = V_64 . V_69 ;
V_63 -> V_70 = V_64 . V_70 ;
V_63 -> V_71 = V_64 . V_71 ;
F_37 ( & V_63 -> V_72 , ( void * ) & V_64 . V_72 ,
sizeof( * V_63 ) - F_38 ( struct V_62 , V_72 ) ) ;
V_63 -> V_65 &= ~ V_66 ;
V_63 -> V_73 = V_64 . V_73 ;
V_63 -> V_74 = V_64 . V_74 ;
V_63 -> V_75 = V_64 . V_75 ;
V_63 -> V_65 = V_64 . V_65 ;
return 0 ;
}

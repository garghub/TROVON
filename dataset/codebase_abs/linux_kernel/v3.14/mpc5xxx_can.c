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
const char * V_20 , int * V_4 )
{
struct V_8 * V_21 ;
T_1 V_22 ;
enum {
V_23 ,
V_24 ,
V_25 ,
V_26 ,
} V_27 ;
struct V_28 * V_29 , * V_30 ;
unsigned long V_31 ;
struct V_32 * V_33 ;
struct V_28 * V_34 ;
V_21 = V_2 -> V_15 . V_16 ;
V_22 = 1 ;
F_12 ( V_21 , L_3 , & V_22 ) ;
F_13 ( & V_2 -> V_15 , L_4 ,
V_20 ? V_20 : L_5 , V_22 ) ;
V_27 = V_23 ;
if ( V_20 ) {
if ( ! strcmp ( V_20 , L_1 ) )
V_27 = V_24 ;
else if ( ! strcmp ( V_20 , L_6 ) )
V_27 = V_25 ;
else if ( ! strcmp ( V_20 , L_7 ) )
V_27 = V_26 ;
else
goto V_35;
F_13 ( & V_2 -> V_15 , L_8 , V_27 ) ;
}
if ( V_27 == V_23 ) {
F_13 ( & V_2 -> V_15 , L_9 ) ;
V_29 = F_14 ( & V_2 -> V_15 , L_6 ) ;
if ( F_15 ( V_29 ) )
goto V_36;
V_31 = F_16 ( V_29 ) ;
V_31 += 499999 ;
V_31 /= 1000000 ;
V_31 *= 1000000 ;
if ( ( V_31 % 16000000 ) == 0 ) {
V_27 = V_25 ;
V_22 = V_31 / 16000000 ;
F_13 ( & V_2 -> V_15 ,
L_10 ,
V_31 , V_22 , V_31 / V_22 ) ;
}
}
if ( V_27 == V_23 ) {
F_13 ( & V_2 -> V_15 , L_11 ) ;
V_29 = F_14 ( & V_2 -> V_15 , L_7 ) ;
if ( F_15 ( V_29 ) )
goto V_36;
V_27 = V_26 ;
V_31 = F_16 ( V_29 ) ;
F_13 ( & V_2 -> V_15 ,
L_12 ,
V_31 , V_31 ) ;
}
switch ( V_27 ) {
case V_24 :
V_30 = F_14 ( & V_2 -> V_15 , L_13 ) ;
if ( F_15 ( V_30 ) )
goto V_36;
V_33 = F_17 ( F_18 ( & V_2 -> V_15 ) ) ;
V_33 -> V_30 = V_30 ;
V_31 = F_16 ( V_30 ) ;
* V_4 = V_37 ;
F_13 ( & V_2 -> V_15 , L_14 ,
* V_4 , V_31 ) ;
break;
case V_25 :
case V_26 :
V_30 = F_14 ( & V_2 -> V_15 , L_15 ) ;
if ( F_15 ( V_30 ) )
goto V_36;
V_33 = F_17 ( F_18 ( & V_2 -> V_15 ) ) ;
V_33 -> V_30 = V_30 ;
if ( V_27 == V_25 )
V_29 = F_14 ( & V_2 -> V_15 , L_6 ) ;
if ( V_27 == V_26 )
V_29 = F_14 ( & V_2 -> V_15 , L_7 ) ;
if ( F_15 ( V_29 ) )
goto V_36;
F_19 ( V_30 , V_29 ) ;
V_31 = F_16 ( V_29 ) ;
V_31 /= V_22 ;
F_20 ( V_30 , V_31 ) ;
V_31 = F_16 ( V_30 ) ;
* V_4 = V_13 ;
F_13 ( & V_2 -> V_15 , L_16 ,
* V_4 , V_31 ) ;
break;
default:
goto V_35;
}
V_34 = F_14 ( & V_2 -> V_15 , L_17 ) ;
if ( F_15 ( V_34 ) )
goto V_38;
if ( F_21 ( V_34 ) )
goto V_38;
V_33 = F_17 ( F_18 ( & V_2 -> V_15 ) ) ;
V_33 -> V_34 = V_34 ;
return V_31 ;
V_35:
F_5 ( & V_2 -> V_15 , L_18 ) ;
return 0 ;
V_36:
F_5 ( & V_2 -> V_15 , L_19 ) ;
return 0 ;
V_38:
F_5 ( & V_2 -> V_15 , L_20 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
V_33 = F_17 ( F_18 ( & V_2 -> V_15 ) ) ;
if ( V_33 -> V_34 )
F_23 ( V_33 -> V_34 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , int * V_4 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
struct V_8 * V_21 = V_2 -> V_15 . V_16 ;
struct V_43 * V_15 ;
struct V_32 * V_33 ;
void T_2 * V_44 ;
const char * V_3 = NULL ;
int V_45 , V_4 = 0 ;
int V_46 = - V_47 ;
V_40 = F_25 ( V_48 , & V_2 -> V_15 ) ;
if ( ! V_40 )
return - V_49 ;
V_42 = V_40 -> V_42 ;
V_44 = F_6 ( V_21 , 0 ) ;
if ( ! V_44 ) {
F_5 ( & V_2 -> V_15 , L_21 ) ;
return V_46 ;
}
V_45 = F_26 ( V_21 , 0 ) ;
if ( ! V_45 ) {
F_5 ( & V_2 -> V_15 , L_22 ) ;
V_46 = - V_50 ;
goto V_51;
}
V_15 = F_27 () ;
if ( ! V_15 )
goto V_52;
F_28 ( V_2 , V_15 ) ;
F_29 ( V_15 , & V_2 -> V_15 ) ;
V_33 = F_17 ( V_15 ) ;
V_33 -> V_53 = V_44 ;
V_15 -> V_45 = V_45 ;
V_3 = F_30 ( V_21 , L_23 , NULL ) ;
F_31 ( ! V_42 ) ;
V_33 -> type = V_42 -> type ;
V_33 -> V_54 . clock . V_10 = V_42 -> V_55 ( V_2 , V_3 ,
& V_4 ) ;
if ( ! V_33 -> V_54 . clock . V_10 ) {
F_5 ( & V_2 -> V_15 , L_24 ) ;
goto V_56;
}
V_46 = F_32 ( V_15 , V_4 ) ;
if ( V_46 ) {
F_5 ( & V_2 -> V_15 , L_25 ,
V_57 , V_46 ) ;
goto V_56;
}
F_33 ( & V_2 -> V_15 , L_26 ,
V_33 -> V_53 , V_15 -> V_45 , V_33 -> V_54 . clock . V_10 ) ;
return 0 ;
V_56:
F_34 ( V_15 ) ;
V_52:
F_35 ( V_45 ) ;
V_51:
F_10 ( V_44 ) ;
return V_46 ;
}
static int F_36 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
struct V_43 * V_15 = F_37 ( V_2 ) ;
struct V_32 * V_33 = F_17 ( V_15 ) ;
V_40 = F_25 ( V_48 , & V_2 -> V_15 ) ;
V_42 = V_40 ? V_40 -> V_42 : NULL ;
F_38 ( V_15 ) ;
if ( V_42 && V_42 -> V_58 )
V_42 -> V_58 ( V_2 ) ;
F_10 ( V_33 -> V_53 ) ;
F_35 ( V_15 -> V_45 ) ;
F_34 ( V_15 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_59 )
{
struct V_43 * V_15 = F_37 ( V_2 ) ;
struct V_32 * V_33 = F_17 ( V_15 ) ;
struct V_60 * V_61 = (struct V_60 * ) V_33 -> V_53 ;
F_40 ( & V_62 , V_61 , sizeof( * V_61 ) ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_43 * V_15 = F_37 ( V_2 ) ;
struct V_32 * V_33 = F_17 ( V_15 ) ;
struct V_60 * V_61 = (struct V_60 * ) V_33 -> V_53 ;
V_61 -> V_63 |= V_64 ;
while ( ! ( V_61 -> V_65 & V_66 ) )
F_42 ( 10 ) ;
V_61 -> V_65 = V_62 . V_65 ;
V_61 -> V_67 = V_62 . V_67 ;
V_61 -> V_68 = V_62 . V_68 ;
V_61 -> V_69 = V_62 . V_69 ;
F_43 ( & V_61 -> V_70 , ( void * ) & V_62 . V_70 ,
sizeof( * V_61 ) - F_44 ( struct V_60 , V_70 ) ) ;
V_61 -> V_63 &= ~ V_64 ;
V_61 -> V_71 = V_62 . V_71 ;
V_61 -> V_72 = V_62 . V_72 ;
V_61 -> V_73 = V_62 . V_73 ;
V_61 -> V_63 = V_62 . V_63 ;
return 0 ;
}

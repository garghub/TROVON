static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] ;
if ( V_4 == & V_15 ) {
return F_4 ( V_5 , V_16 , L_1 ,
F_5 ( & V_13 -> V_17 ) ) ;
} else if ( V_4 == & V_18 ) {
return F_4 ( V_5 , V_16 , L_1 ,
F_5 ( & V_13 -> V_19 ) ) ;
}
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] ;
unsigned long V_21 ;
T_3 V_22 ;
T_3 V_23 ;
T_3 V_24 ;
if ( F_7 ( V_5 , 0 , & V_21 ) != 0 )
return - V_25 ;
V_24 = ( T_3 ) V_21 ;
V_22 = F_5 ( & V_13 -> V_17 ) ;
V_23 = F_5 ( & V_13 -> V_19 ) ;
if ( V_4 == & V_15 ) {
if ( ( V_22 & V_23 & V_26 ) !=
( V_24 & V_23 & V_26 ) ) {
return - V_25 ;
}
if ( ( V_24 & V_27 ) != V_28 )
return - V_25 ;
F_8 ( & V_13 -> V_17 , V_24 | V_29 ) ;
} else if ( V_4 == & V_18 ) {
if ( ( V_23 & V_30 ) != ( V_24 & V_30 ) )
return - V_25 ;
F_8 ( & V_13 -> V_19 , V_24 ) ;
} else {
return - V_25 ;
}
return V_20 ;
}
static T_4 F_9 ( int V_31 , struct V_8 * V_9 )
{
void T_5 * V_32 = V_9 -> V_33 [ 0 ] . V_34 +
V_35 +
V_36 ;
void T_5 * V_37 = V_9 -> V_33 [ 0 ] . V_34 +
V_35 +
V_38 ;
if ( ( F_10 ( V_32 ) & F_10 ( V_37 ) &
V_39 ) == 0 ) {
return V_40 ;
}
F_11 ( F_10 ( V_32 ) & ~ V_41 , V_32 ) ;
return V_42 ;
}
static void F_12 ( struct V_8 * V_9 )
{
unsigned long V_43 = V_35 ;
struct V_10 * V_11 = V_9 -> V_11 ;
const void * V_44 ;
V_44 = F_13 ( V_11 -> V_2 -> V_45 ,
L_2 , NULL ) ;
if ( V_44 )
V_43 = F_14 ( V_44 , 1 ) ;
F_11 ( 0 , V_9 -> V_33 [ 0 ] . V_34 + V_43 +
V_36 ) ;
}
static void F_15 ( struct V_8 * V_9 , bool V_46 )
{
if ( V_46 )
return;
F_11 ( 0 , V_9 -> V_33 [ 0 ] . V_34 + V_35 +
V_36 ) ;
}
static void F_16 ( struct V_10 * V_11 ,
const char * type )
{
#ifdef F_17
if ( strcmp ( type , L_3 ) == 0 ) {
V_11 -> V_47 = F_9 ;
V_11 -> V_48 = F_12 ;
V_11 -> V_49 = F_15 ;
V_11 -> V_50 = L_4 ;
return;
}
#endif
}
static int F_18 ( struct V_10 * V_11 ,
struct V_51 * V_52 ,
T_3 V_53 , T_3 V_54 )
{
if ( V_11 -> V_13 >= V_55 ) {
F_19 ( V_11 -> V_2 , L_5 ) ;
return - V_56 ;
}
if ( ( V_53 & V_27 ) != V_28 ) {
F_19 ( V_11 -> V_2 , L_6 ) ;
return - V_56 ;
}
if ( ( ~ ( V_54 & V_30 ) + 1 ) != F_20 ( V_52 ) ) {
F_19 ( V_11 -> V_2 , L_7 ) ;
return - V_56 ;
}
if ( ( V_53 & V_54 & V_26 ) != F_21 ( V_52 -> V_57 ) ) {
F_19 ( V_11 -> V_2 , L_8 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_11 , struct V_58 * V_59 ,
struct V_51 * V_52 , T_3 * V_53 ,
T_3 * V_54 , unsigned int * V_31 , char * * V_50 )
{
const char * V_60 ;
const char * type ;
int V_61 ;
V_61 = F_23 ( V_59 , 0 , V_52 ) ;
if ( V_61 ) {
F_19 ( V_11 -> V_2 , L_9 ) ;
return V_61 ;
}
V_61 = F_24 ( V_59 , L_10 , & V_11 -> V_13 ) ;
if ( V_61 ) {
F_19 ( V_11 -> V_2 , L_11 ) ;
return V_61 ;
}
V_61 = F_24 ( V_59 , L_12 , V_53 ) ;
if ( V_61 ) {
F_19 ( V_11 -> V_2 , L_13 ) ;
return V_61 ;
}
V_61 = F_24 ( V_59 , L_14 , V_54 ) ;
if ( V_61 ) {
F_19 ( V_11 -> V_2 , L_15 ) ;
return V_61 ;
}
V_11 -> V_50 = L_16 ;
if ( F_25 ( V_59 , L_17 , & type ) == 0 )
F_16 ( V_11 , type ) ;
* V_31 = F_26 ( V_59 , 0 ) ;
V_61 = F_18 ( V_11 , V_52 , * V_53 , * V_54 ) ;
if ( V_61 )
return V_61 ;
if ( F_25 ( V_59 , L_18 , & V_60 ) != 0 )
V_60 = L_19 ;
* V_50 = F_27 ( V_60 , V_62 ) ;
if ( ! * V_50 )
return - V_63 ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_58 * V_59 = V_7 -> V_2 . V_45 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
char * V_64 = NULL ;
struct V_51 V_52 ;
unsigned int V_31 ;
T_3 V_22 ;
T_3 V_23 ;
T_3 V_65 ;
T_3 V_66 ;
int V_61 ;
if ( ! V_67 || ! V_67 -> V_68 )
return - V_56 ;
V_11 = F_29 ( sizeof( * V_11 ) , V_62 ) ;
if ( ! V_11 )
return - V_63 ;
V_11 -> V_2 = & V_7 -> V_2 ;
V_11 -> V_14 = V_67 -> V_68 ;
V_61 = F_22 ( V_11 , V_59 , & V_52 , & V_65 , & V_66 ,
& V_31 , & V_64 ) ;
if ( V_61 )
goto V_69;
V_9 = F_29 ( sizeof( * V_9 ) , V_62 ) ;
if ( ! V_9 ) {
V_61 = - V_63 ;
goto V_69;
}
V_22 = F_5 ( & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] . V_17 ) ;
V_23 = F_5 ( & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] . V_19 ) ;
if ( ( V_22 & V_29 ) ) {
if ( ( V_22 & V_27 ) != V_28 ||
( V_22 & V_23 & V_26 )
!= F_21 ( V_52 . V_57 ) ) {
F_19 ( V_11 -> V_2 ,
L_20 ) ;
V_61 = - V_56 ;
goto V_70;
}
if ( ( V_22 & ~ ( V_26 | V_29 ) ) !=
( V_65 & ~ ( V_26 | V_29 ) ) ) {
F_30 ( V_11 -> V_2 ,
L_21 ,
V_22 , V_65 ) ;
}
if ( ( V_23 & ~ V_30 ) != ( V_66 & ~ V_30 ) ) {
F_30 ( V_11 -> V_2 ,
L_22 ,
V_23 , V_66 ) ;
}
}
V_65 &= ~ ( V_26 | V_27 ) ;
V_65 |= F_21 ( V_52 . V_57 ) | V_28 | V_29 ;
F_8 ( & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] . V_19 , V_66 ) ;
F_8 ( & V_11 -> V_14 -> V_13 [ V_11 -> V_13 ] . V_17 , V_65 ) ;
V_9 -> V_33 [ 0 ] . V_34 = F_31 ( V_52 . V_57 , F_20 ( & V_52 ) ) ;
if ( ! V_9 -> V_33 [ 0 ] . V_34 ) {
F_19 ( V_11 -> V_2 , L_23 ) ;
V_61 = - V_56 ;
goto V_70;
}
if ( V_59 -> V_50 )
V_9 -> V_33 [ 0 ] . V_50 = F_27 ( V_59 -> V_50 , V_62 ) ;
V_9 -> V_33 [ 0 ] . V_71 = V_52 . V_57 ;
V_9 -> V_33 [ 0 ] . V_72 = F_20 ( & V_52 ) ;
V_9 -> V_33 [ 0 ] . V_73 = V_74 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_50 = V_64 ;
V_9 -> V_75 = L_24 ;
if ( V_31 != V_76 ) {
if ( V_11 -> V_47 ) {
V_9 -> V_31 = V_31 ;
V_9 -> V_77 = V_78 ;
V_9 -> V_79 = V_11 -> V_47 ;
} else {
V_31 = V_76 ;
F_30 ( V_11 -> V_2 , L_25 ) ;
}
}
if ( V_11 -> V_48 )
V_11 -> V_48 ( V_9 ) ;
if ( F_32 ( V_11 -> V_2 , V_9 ) != 0 ) {
F_19 ( V_11 -> V_2 , L_26 ) ;
V_61 = - V_56 ;
goto V_80;
}
F_33 ( V_7 , V_9 ) ;
V_61 = F_34 ( V_11 -> V_2 , & V_15 ) ;
if ( V_61 )
goto V_81;
V_61 = F_34 ( V_11 -> V_2 , & V_18 ) ;
if ( V_61 )
goto V_82;
F_35 ( V_11 -> V_2 ,
L_27 ,
V_11 -> V_50 , ( unsigned long long ) V_52 . V_57 , V_11 -> V_13 ,
V_31 != V_76 ? V_31 : - 1 ) ;
return 0 ;
V_82:
F_36 ( V_11 -> V_2 , & V_15 ) ;
V_81:
F_33 ( V_7 , NULL ) ;
F_37 ( V_9 ) ;
V_80:
if ( V_11 -> V_49 )
V_11 -> V_49 ( V_9 , true ) ;
F_38 ( V_9 -> V_33 [ 0 ] . V_34 ) ;
V_70:
F_39 ( V_9 -> V_33 [ 0 ] . V_50 ) ;
F_39 ( V_9 ) ;
V_69:
F_39 ( V_64 ) ;
F_39 ( V_11 ) ;
return V_61 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_36 ( V_11 -> V_2 , & V_18 ) ;
F_36 ( V_11 -> V_2 , & V_15 ) ;
F_33 ( V_7 , NULL ) ;
F_37 ( V_9 ) ;
if ( V_11 -> V_49 )
V_11 -> V_49 ( V_9 , false ) ;
F_38 ( V_9 -> V_33 [ 0 ] . V_34 ) ;
F_39 ( V_9 -> V_33 [ 0 ] . V_50 ) ;
F_39 ( V_9 -> V_50 ) ;
F_39 ( V_9 ) ;
F_39 ( V_11 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_83 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_83 ) ;
}

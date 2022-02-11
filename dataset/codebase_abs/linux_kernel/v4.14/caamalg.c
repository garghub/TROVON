static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
int V_8 = V_9 - V_10 -
V_4 -> V_11 . V_12 ;
if ( V_8 >= V_13 ) {
V_4 -> V_11 . V_14 = true ;
V_4 -> V_11 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_11 . V_14 = false ;
V_4 -> V_11 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_18 ;
F_3 ( V_7 , & V_4 -> V_11 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
if ( V_8 >= V_22 ) {
V_4 -> V_11 . V_14 = true ;
V_4 -> V_11 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_11 . V_14 = false ;
V_4 -> V_11 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_23 ;
F_6 ( V_7 , & V_4 -> V_11 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_8 ( F_9 ( V_2 ) ,
struct V_25 , V_2 ) ;
unsigned int V_27 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_28 = 0 ;
T_1 * V_7 , * V_29 = NULL ;
T_1 V_30 ;
unsigned int V_31 [ 2 ] ;
const bool V_32 = ( ( V_4 -> V_33 . V_34 & V_35 ) ==
V_36 ) ;
const bool V_37 = V_26 -> V_38 . V_39 ;
if ( ! V_4 -> V_19 )
return 0 ;
if ( ! V_4 -> V_33 . V_40 )
return F_1 ( V_2 ) ;
if ( V_32 )
V_28 = 16 ;
if ( V_37 ) {
V_28 = 16 + V_41 ;
V_29 = ( T_1 * ) ( ( void * ) V_4 -> V_16 + V_4 -> V_11 . V_12 +
V_4 -> V_33 . V_40 - V_41 ) ;
}
V_31 [ 0 ] = V_4 -> V_11 . V_12 ;
V_31 [ 1 ] = V_4 -> V_33 . V_40 ;
if ( V_26 -> V_38 . V_42 )
goto V_43;
if ( F_11 ( V_44 +
( V_37 ? V_45 : 0 ) ,
V_46 , V_31 , & V_30 ,
F_12 ( V_31 ) ) < 0 )
return - V_47 ;
if ( V_30 & 1 )
V_4 -> V_11 . V_15 = V_4 -> V_16 ;
else
V_4 -> V_11 . V_17 = V_4 -> V_17 ;
if ( V_30 & 2 )
V_4 -> V_33 . V_15 = V_4 -> V_16 + V_4 -> V_11 . V_12 ;
else
V_4 -> V_33 . V_17 = V_4 -> V_17 + V_4 -> V_11 . V_12 ;
V_4 -> V_11 . V_14 = ! ! ( V_30 & 1 ) ;
V_4 -> V_33 . V_14 = ! ! ( V_30 & 2 ) ;
V_7 = V_4 -> V_18 ;
F_13 ( V_7 , & V_4 -> V_33 , & V_4 -> V_11 , V_27 ,
V_4 -> V_19 , V_37 , V_29 , V_28 ,
false ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
V_43:
if ( F_11 ( V_48 +
( V_37 ? V_45 : 0 ) ,
V_46 , V_31 , & V_30 ,
F_12 ( V_31 ) ) < 0 )
return - V_47 ;
if ( V_30 & 1 )
V_4 -> V_11 . V_15 = V_4 -> V_16 ;
else
V_4 -> V_11 . V_17 = V_4 -> V_17 ;
if ( V_30 & 2 )
V_4 -> V_33 . V_15 = V_4 -> V_16 + V_4 -> V_11 . V_12 ;
else
V_4 -> V_33 . V_17 = V_4 -> V_17 + V_4 -> V_11 . V_12 ;
V_4 -> V_11 . V_14 = ! ! ( V_30 & 1 ) ;
V_4 -> V_33 . V_14 = ! ! ( V_30 & 2 ) ;
V_7 = V_4 -> V_23 ;
F_14 ( V_7 , & V_4 -> V_33 , & V_4 -> V_11 , V_27 ,
V_4 -> V_19 , V_26 -> V_38 . V_42 , V_37 ,
V_29 , V_28 , false ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
if ( ! V_26 -> V_38 . V_42 )
goto V_49;
if ( F_11 ( V_50 +
( V_37 ? V_45 : 0 ) ,
V_46 , V_31 , & V_30 ,
F_12 ( V_31 ) ) < 0 )
return - V_47 ;
if ( V_30 & 1 )
V_4 -> V_11 . V_15 = V_4 -> V_16 ;
else
V_4 -> V_11 . V_17 = V_4 -> V_17 ;
if ( V_30 & 2 )
V_4 -> V_33 . V_15 = V_4 -> V_16 + V_4 -> V_11 . V_12 ;
else
V_4 -> V_33 . V_17 = V_4 -> V_17 + V_4 -> V_11 . V_12 ;
V_4 -> V_11 . V_14 = ! ! ( V_30 & 1 ) ;
V_4 -> V_33 . V_14 = ! ! ( V_30 & 2 ) ;
V_7 = V_4 -> V_18 ;
F_15 ( V_7 , & V_4 -> V_33 , & V_4 -> V_11 , V_27 ,
V_4 -> V_19 , V_37 , V_29 ,
V_28 , false ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
V_49:
return 0 ;
}
static int F_16 ( struct V_1 * V_51 ,
unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_51 ) ;
V_4 -> V_19 = V_19 ;
F_7 ( V_51 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
int V_8 = V_9 - V_52 -
V_4 -> V_33 . V_40 ;
if ( ! V_4 -> V_33 . V_40 || ! V_4 -> V_19 )
return 0 ;
if ( V_8 >= V_53 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_18 ;
F_18 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
if ( V_8 >= V_54 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_23 ;
F_19 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_51 , unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_51 ) ;
V_4 -> V_19 = V_19 ;
F_17 ( V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
int V_8 = V_9 - V_52 -
V_4 -> V_33 . V_40 ;
if ( ! V_4 -> V_33 . V_40 || ! V_4 -> V_19 )
return 0 ;
if ( V_8 >= V_55 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_18 ;
F_22 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
if ( V_8 >= V_56 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_23 ;
F_23 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_51 ,
unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_51 ) ;
V_4 -> V_19 = V_19 ;
F_21 ( V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
int V_8 = V_9 - V_52 -
V_4 -> V_33 . V_40 ;
if ( ! V_4 -> V_33 . V_40 || ! V_4 -> V_19 )
return 0 ;
if ( V_8 >= V_57 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_18 ;
F_26 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
if ( V_8 >= V_58 ) {
V_4 -> V_33 . V_14 = true ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
} else {
V_4 -> V_33 . V_14 = false ;
V_4 -> V_33 . V_17 = V_4 -> V_17 ;
}
V_7 = V_4 -> V_23 ;
F_27 ( V_7 , & V_4 -> V_33 , V_4 -> V_19 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_51 ,
unsigned int V_19 )
{
struct V_3 * V_4 = F_2 ( V_51 ) ;
V_4 -> V_19 = V_19 ;
F_25 ( V_51 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_59 V_60 ;
int V_61 = 0 ;
if ( F_30 ( & V_60 , V_16 , V_40 ) != 0 )
goto V_62;
#ifdef F_31
F_32 ( V_63 L_1 ,
V_60 . V_64 + V_60 . V_65 , V_60 . V_65 ,
V_60 . V_64 ) ;
F_33 ( V_63 , L_2 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_16 , V_40 , 1 ) ;
#endif
V_61 = F_35 ( V_4 -> V_6 , V_4 -> V_16 , & V_4 -> V_11 , V_60 . V_67 ,
V_60 . V_64 , V_68 -
V_60 . V_65 ) ;
if ( V_61 ) {
goto V_62;
}
memcpy ( V_4 -> V_16 + V_4 -> V_11 . V_12 , V_60 . V_69 , V_60 . V_65 ) ;
F_4 ( V_6 , V_4 -> V_17 , V_4 -> V_11 . V_12 +
V_60 . V_65 , V_21 ) ;
#ifdef F_31
F_33 ( V_63 , L_4 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_4 -> V_16 ,
V_4 -> V_11 . V_12 + V_60 . V_65 , 1 ) ;
#endif
V_4 -> V_33 . V_40 = V_60 . V_65 ;
return F_7 ( V_2 ) ;
V_62:
F_36 ( V_2 , V_70 ) ;
return - V_47 ;
}
static int F_37 ( struct V_1 * V_2 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
#ifdef F_31
F_33 ( V_63 , L_2 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_16 , V_40 , 1 ) ;
#endif
memcpy ( V_4 -> V_16 , V_16 , V_40 ) ;
F_4 ( V_6 , V_4 -> V_17 , V_40 , V_21 ) ;
V_4 -> V_33 . V_40 = V_40 ;
return F_17 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_40 < 4 )
return - V_47 ;
#ifdef F_31
F_33 ( V_63 , L_2 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_16 , V_40 , 1 ) ;
#endif
memcpy ( V_4 -> V_16 , V_16 , V_40 ) ;
V_4 -> V_33 . V_40 = V_40 - 4 ;
F_4 ( V_6 , V_4 -> V_17 , V_4 -> V_33 . V_40 ,
V_21 ) ;
return F_21 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_40 < 4 )
return - V_47 ;
#ifdef F_31
F_33 ( V_63 , L_2 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_16 , V_40 , 1 ) ;
#endif
memcpy ( V_4 -> V_16 , V_16 , V_40 ) ;
V_4 -> V_33 . V_40 = V_40 - 4 ;
F_4 ( V_6 , V_4 -> V_17 , V_4 -> V_33 . V_40 ,
V_21 ) ;
return F_25 ( V_2 ) ;
}
static int F_40 ( struct V_71 * V_72 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_73 * V_74 = F_42 ( V_72 ) ;
const char * V_75 = F_43 ( V_74 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_27 = F_44 ( V_72 ) ;
T_1 * V_7 ;
T_1 V_28 = 0 ;
const bool V_32 = ( ( V_4 -> V_33 . V_34 & V_35 ) ==
V_36 ) ;
const bool V_37 = ( V_32 &&
( strstr ( V_75 , L_5 ) != NULL ) ) ;
memcpy ( V_4 -> V_16 , V_16 , V_40 ) ;
#ifdef F_31
F_33 ( V_63 , L_2 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_16 , V_40 , 1 ) ;
#endif
if ( V_32 )
V_28 = 16 ;
if ( V_37 ) {
V_28 = 16 + V_41 ;
V_40 -= V_41 ;
}
F_4 ( V_6 , V_4 -> V_17 , V_40 , V_21 ) ;
V_4 -> V_33 . V_40 = V_40 ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
V_4 -> V_33 . V_14 = true ;
V_7 = V_4 -> V_18 ;
F_45 ( V_7 , & V_4 -> V_33 , V_27 , V_37 ,
V_28 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
V_7 = V_4 -> V_23 ;
F_46 ( V_7 , & V_4 -> V_33 , V_27 , V_37 ,
V_28 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
V_7 = V_4 -> V_76 ;
F_47 ( V_7 , & V_4 -> V_33 , V_27 , V_37 ,
V_28 ) ;
F_4 ( V_6 , V_4 -> V_77 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static int F_48 ( struct V_71 * V_72 ,
const T_2 * V_16 , unsigned int V_40 )
{
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
if ( V_40 != 2 * V_78 && V_40 != 2 * V_79 ) {
F_49 ( V_72 ,
V_70 ) ;
F_50 ( V_6 , L_6 ) ;
return - V_47 ;
}
memcpy ( V_4 -> V_16 , V_16 , V_40 ) ;
F_4 ( V_6 , V_4 -> V_17 , V_40 , V_21 ) ;
V_4 -> V_33 . V_40 = V_40 ;
V_4 -> V_33 . V_15 = V_4 -> V_16 ;
V_4 -> V_33 . V_14 = true ;
V_7 = V_4 -> V_18 ;
F_51 ( V_7 , & V_4 -> V_33 ) ;
F_4 ( V_6 , V_4 -> V_20 ,
F_5 ( V_7 ) , V_21 ) ;
V_7 = V_4 -> V_23 ;
F_52 ( V_7 , & V_4 -> V_33 ) ;
F_4 ( V_6 , V_4 -> V_24 ,
F_5 ( V_7 ) , V_21 ) ;
return 0 ;
}
static void F_53 ( struct V_5 * V_80 , struct V_81 * V_82 ,
struct V_81 * V_83 , int V_84 ,
int V_85 ,
T_3 V_86 , int V_27 , T_3 V_87 ,
int V_88 )
{
if ( V_83 != V_82 ) {
if ( V_84 )
F_54 ( V_80 , V_82 , V_84 , V_21 ) ;
F_54 ( V_80 , V_83 , V_85 , V_89 ) ;
} else {
F_54 ( V_80 , V_82 , V_84 , V_90 ) ;
}
if ( V_86 )
F_55 ( V_80 , V_86 , V_27 , V_21 ) ;
if ( V_88 )
F_55 ( V_80 , V_87 , V_88 ,
V_21 ) ;
}
static void F_56 ( struct V_5 * V_80 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
F_53 ( V_80 , V_94 -> V_82 , V_94 -> V_83 ,
V_92 -> V_84 , V_92 -> V_85 , 0 , 0 ,
V_92 -> V_87 , V_92 -> V_88 ) ;
}
static void F_57 ( struct V_5 * V_80 ,
struct V_95 * V_92 ,
struct V_96 * V_94 )
{
struct V_71 * V_72 = F_58 ( V_94 ) ;
int V_27 = F_44 ( V_72 ) ;
F_53 ( V_80 , V_94 -> V_82 , V_94 -> V_83 ,
V_92 -> V_84 , V_92 -> V_85 ,
V_92 -> V_86 , V_27 ,
V_92 -> V_87 , V_92 -> V_88 ) ;
}
static void F_59 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_97 ,
void * V_98 )
{
struct V_93 * V_94 = V_98 ;
struct V_91 * V_92 ;
#ifdef F_31
F_50 ( V_6 , L_7 , V_99 , __LINE__ , V_97 ) ;
#endif
V_92 = F_8 ( V_7 , struct V_91 , V_100 [ 0 ] ) ;
if ( V_97 )
F_60 ( V_6 , V_97 ) ;
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
F_62 ( V_94 , V_97 ) ;
}
static void F_63 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_97 ,
void * V_98 )
{
struct V_93 * V_94 = V_98 ;
struct V_91 * V_92 ;
#ifdef F_31
F_50 ( V_6 , L_7 , V_99 , __LINE__ , V_97 ) ;
#endif
V_92 = F_8 ( V_7 , struct V_91 , V_100 [ 0 ] ) ;
if ( V_97 )
F_60 ( V_6 , V_97 ) ;
F_56 ( V_6 , V_92 , V_94 ) ;
if ( ( V_97 & V_101 ) == V_102 )
V_97 = - V_103 ;
F_61 ( V_92 ) ;
F_62 ( V_94 , V_97 ) ;
}
static void F_64 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_97 ,
void * V_98 )
{
struct V_96 * V_94 = V_98 ;
struct V_95 * V_92 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
int V_27 = F_44 ( V_72 ) ;
#ifdef F_31
F_50 ( V_6 , L_7 , V_99 , __LINE__ , V_97 ) ;
#endif
V_92 = F_8 ( V_7 , struct V_95 , V_100 [ 0 ] ) ;
if ( V_97 )
F_60 ( V_6 , V_97 ) ;
#ifdef F_31
F_33 ( V_63 , L_8 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_104 ,
V_92 -> V_84 > 1 ? 100 : V_27 , 1 ) ;
#endif
F_65 ( V_63 , L_9 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_83 ,
V_92 -> V_85 > 1 ? 100 : V_94 -> V_105 , 1 ) ;
F_57 ( V_6 , V_92 , V_94 ) ;
F_66 ( V_94 -> V_104 , V_94 -> V_83 , V_94 -> V_105 - V_27 ,
V_27 , 0 ) ;
F_61 ( V_92 ) ;
F_67 ( V_94 , V_97 ) ;
}
static void F_68 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_97 ,
void * V_98 )
{
struct V_96 * V_94 = V_98 ;
struct V_95 * V_92 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
int V_27 = F_44 ( V_72 ) ;
#ifdef F_31
F_50 ( V_6 , L_7 , V_99 , __LINE__ , V_97 ) ;
#endif
V_92 = F_8 ( V_7 , struct V_95 , V_100 [ 0 ] ) ;
if ( V_97 )
F_60 ( V_6 , V_97 ) ;
#ifdef F_31
F_33 ( V_63 , L_8 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_104 ,
V_27 , 1 ) ;
#endif
F_65 ( V_63 , L_9 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_83 ,
V_92 -> V_85 > 1 ? 100 : V_94 -> V_105 , 1 ) ;
F_57 ( V_6 , V_92 , V_94 ) ;
F_66 ( V_94 -> V_104 , V_94 -> V_82 , V_94 -> V_105 - V_27 ,
V_27 , 0 ) ;
F_61 ( V_92 ) ;
F_67 ( V_94 , V_97 ) ;
}
static void F_69 ( struct V_93 * V_94 ,
struct V_91 * V_92 ,
bool V_106 , bool V_107 )
{
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_19 = V_4 -> V_19 ;
T_1 * V_7 = V_92 -> V_100 ;
T_1 V_108 , V_109 ;
T_3 V_110 , V_111 ;
int V_112 , V_113 = 0 ;
T_3 V_114 ;
T_1 * V_115 ;
V_115 = V_107 ? V_4 -> V_18 : V_4 -> V_23 ;
V_114 = V_107 ? V_4 -> V_20 : V_4 -> V_24 ;
V_112 = F_71 ( V_115 ) ;
F_72 ( V_7 , V_114 , V_112 , V_116 | V_117 ) ;
if ( V_106 ) {
V_111 = V_92 -> V_84 ? F_73 ( V_94 -> V_82 ) : 0 ;
V_109 = 0 ;
} else {
V_111 = V_92 -> V_87 ;
V_113 += V_92 -> V_84 ;
V_109 = V_118 ;
}
F_74 ( V_7 , V_111 , V_94 -> V_119 + V_94 -> V_120 ,
V_109 ) ;
V_110 = V_111 ;
V_108 = V_109 ;
if ( F_75 ( V_94 -> V_82 != V_94 -> V_83 ) ) {
if ( V_92 -> V_85 == 1 ) {
V_110 = F_73 ( V_94 -> V_83 ) ;
} else {
V_110 = V_92 -> V_87 +
V_113 *
sizeof( struct V_121 ) ;
V_108 = V_118 ;
}
}
if ( V_107 )
F_76 ( V_7 , V_110 ,
V_94 -> V_119 + V_94 -> V_120 + V_19 ,
V_108 ) ;
else
F_76 ( V_7 , V_110 ,
V_94 -> V_119 + V_94 -> V_120 - V_19 ,
V_108 ) ;
F_77 ( V_7 , V_122 , V_123 , V_124 , V_94 -> V_119 ) ;
}
static void F_78 ( struct V_93 * V_94 ,
struct V_91 * V_92 ,
bool V_106 , bool V_107 )
{
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_27 = F_10 ( V_2 ) ;
T_1 * V_7 = V_92 -> V_100 ;
bool V_125 = ( V_27 == 12 ) ;
unsigned int V_126 ;
F_69 ( V_94 , V_92 , V_106 , V_107 ) ;
V_126 = 0 ;
if ( V_107 && V_125 && ! ( V_94 -> V_119 + V_94 -> V_120 ) )
V_126 = V_127 ;
F_79 ( V_7 , V_128 | V_129 | V_130 |
V_131 | V_132 | 12 | V_126 ) ;
if ( ! V_125 )
F_80 ( V_7 , V_4 -> V_16 + V_4 -> V_33 . V_40 , 4 ) ;
F_80 ( V_7 , V_94 -> V_133 , V_27 ) ;
}
static void F_81 ( struct V_93 * V_94 ,
struct V_91 * V_92 ,
bool V_106 , bool V_107 )
{
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_25 * V_26 = F_8 ( F_9 ( V_2 ) ,
struct V_25 , V_2 ) ;
unsigned int V_27 = F_10 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const bool V_32 = ( ( V_4 -> V_33 . V_34 & V_35 ) ==
V_36 ) ;
const bool V_37 = V_26 -> V_38 . V_39 ;
T_1 * V_7 = V_92 -> V_100 ;
T_1 V_134 = 0 ;
if ( V_32 )
V_134 = 16 ;
if ( V_37 )
V_134 = 16 + V_41 ;
F_69 ( V_94 , V_92 , V_106 , V_107 ) ;
if ( V_27 && ( ( V_37 && V_107 ) || ! V_26 -> V_38 . V_42 ) )
F_82 ( V_7 , V_94 -> V_133 , V_27 ,
V_135 |
V_136 |
( V_134 << V_137 ) ) ;
}
static void F_83 ( T_1 * V_115 , T_3 V_114 ,
struct V_95 * V_92 ,
struct V_96 * V_94 ,
bool V_138 )
{
struct V_71 * V_72 = F_58 ( V_94 ) ;
int V_27 = F_44 ( V_72 ) ;
T_1 * V_7 = V_92 -> V_100 ;
T_1 V_108 = 0 , V_109 ;
T_3 V_110 , V_111 ;
int V_112 , V_113 = 0 ;
#ifdef F_31
F_33 ( V_63 , L_10 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_104 ,
V_27 , 1 ) ;
F_84 ( L_11 ,
( int ) V_92 -> V_84 > 1 ? 100 : V_94 -> V_105 , V_94 -> V_105 ) ;
#endif
F_65 ( V_63 , L_12 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_82 ,
V_92 -> V_84 > 1 ? 100 : V_94 -> V_105 , 1 ) ;
V_112 = F_71 ( V_115 ) ;
F_72 ( V_7 , V_114 , V_112 , V_116 | V_117 ) ;
if ( V_138 ) {
V_111 = V_92 -> V_86 ;
V_109 = 0 ;
} else {
V_111 = V_92 -> V_87 ;
V_113 += V_92 -> V_84 + 1 ;
V_109 = V_118 ;
}
F_74 ( V_7 , V_111 , V_94 -> V_105 + V_27 , V_109 ) ;
if ( F_85 ( V_94 -> V_82 == V_94 -> V_83 ) ) {
if ( V_92 -> V_84 == 1 && V_138 ) {
V_110 = F_73 ( V_94 -> V_82 ) ;
} else {
V_110 = V_92 -> V_87 +
sizeof( struct V_121 ) ;
V_108 = V_118 ;
}
} else {
if ( V_92 -> V_85 == 1 ) {
V_110 = F_73 ( V_94 -> V_83 ) ;
} else {
V_110 = V_92 -> V_87 +
V_113 * sizeof( struct V_121 ) ;
V_108 = V_118 ;
}
}
F_76 ( V_7 , V_110 , V_94 -> V_105 , V_108 ) ;
}
static void F_86 ( T_1 * V_115 , T_3 V_114 ,
struct V_95 * V_92 ,
struct V_96 * V_94 ,
bool V_138 )
{
struct V_71 * V_72 = F_58 ( V_94 ) ;
int V_27 = F_44 ( V_72 ) ;
T_1 * V_7 = V_92 -> V_100 ;
T_1 V_108 , V_109 ;
T_3 V_110 , V_111 ;
int V_112 , V_113 = 0 ;
#ifdef F_31
F_33 ( V_63 , L_10 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_104 ,
V_27 , 1 ) ;
#endif
F_65 ( V_63 , L_12 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_82 ,
V_92 -> V_84 > 1 ? 100 : V_94 -> V_105 , 1 ) ;
V_112 = F_71 ( V_115 ) ;
F_72 ( V_7 , V_114 , V_112 , V_116 | V_117 ) ;
if ( V_92 -> V_84 == 1 ) {
V_111 = F_73 ( V_94 -> V_82 ) ;
V_109 = 0 ;
} else {
V_111 = V_92 -> V_87 ;
V_113 += V_92 -> V_84 ;
V_109 = V_118 ;
}
F_74 ( V_7 , V_111 , V_94 -> V_105 , V_109 ) ;
if ( V_138 ) {
V_110 = V_92 -> V_86 ;
V_108 = 0 ;
} else {
V_110 = V_92 -> V_87 +
V_113 * sizeof( struct V_121 ) ;
V_108 = V_118 ;
}
F_76 ( V_7 , V_110 , V_94 -> V_105 + V_27 , V_108 ) ;
}
static struct V_91 * F_87 ( struct V_93 * V_94 ,
int F_5 , bool * V_139 ,
bool V_107 )
{
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_140 = ( V_94 -> V_141 . V_140 & V_142 ) ?
V_143 : V_144 ;
int V_84 , V_145 , V_85 = 0 , V_146 = 0 ;
struct V_91 * V_92 ;
int V_113 , V_147 , V_88 ;
unsigned int V_19 = V_4 -> V_19 ;
if ( F_75 ( V_94 -> V_83 != V_94 -> V_82 ) ) {
V_84 = F_88 ( V_94 -> V_82 , V_94 -> V_119 +
V_94 -> V_120 ) ;
if ( F_75 ( V_84 < 0 ) ) {
F_50 ( V_6 , L_13 ,
V_94 -> V_119 + V_94 -> V_120 ) ;
return F_89 ( V_84 ) ;
}
V_85 = F_88 ( V_94 -> V_83 , V_94 -> V_119 +
V_94 -> V_120 +
( V_107 ? V_19 :
( - V_19 ) ) ) ;
if ( F_75 ( V_85 < 0 ) ) {
F_50 ( V_6 , L_14 ,
V_94 -> V_119 + V_94 -> V_120 +
( V_107 ? V_19 : ( - V_19 ) ) ) ;
return F_89 ( V_85 ) ;
}
} else {
V_84 = F_88 ( V_94 -> V_82 , V_94 -> V_119 +
V_94 -> V_120 +
( V_107 ? V_19 : 0 ) ) ;
if ( F_75 ( V_84 < 0 ) ) {
F_50 ( V_6 , L_13 ,
V_94 -> V_119 + V_94 -> V_120 +
( V_107 ? V_19 : 0 ) ) ;
return F_89 ( V_84 ) ;
}
}
if ( F_85 ( V_94 -> V_82 == V_94 -> V_83 ) ) {
V_145 = F_90 ( V_6 , V_94 -> V_82 , V_84 ,
V_90 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
} else {
if ( V_84 ) {
V_145 = F_90 ( V_6 , V_94 -> V_82 ,
V_84 , V_21 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
} else {
V_145 = 0 ;
}
V_146 = F_90 ( V_6 , V_94 -> V_83 , V_85 ,
V_89 ) ;
if ( F_75 ( ! V_146 ) ) {
F_50 ( V_6 , L_16 ) ;
F_54 ( V_6 , V_94 -> V_82 , V_84 , V_21 ) ;
return F_89 ( - V_148 ) ;
}
}
V_147 = V_145 > 1 ? V_145 : 0 ;
V_147 += V_146 > 1 ? V_146 : 0 ;
V_88 = V_147 * sizeof( struct V_121 ) ;
V_92 = F_91 ( sizeof( * V_92 ) + F_5 + V_88 ,
V_149 | V_140 ) ;
if ( ! V_92 ) {
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 , 0 ,
0 , 0 , 0 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_84 = V_84 ;
V_92 -> V_85 = V_85 ;
V_92 -> V_150 = ( void * ) V_92 + sizeof( struct V_91 ) +
F_5 ;
* V_139 = ! ( V_145 > 1 ) ;
V_113 = 0 ;
if ( V_145 > 1 ) {
F_92 ( V_94 -> V_82 , V_145 ,
V_92 -> V_150 + V_113 , 0 ) ;
V_113 += V_145 ;
}
if ( V_146 > 1 ) {
F_92 ( V_94 -> V_83 , V_146 ,
V_92 -> V_150 + V_113 , 0 ) ;
}
if ( ! V_88 )
return V_92 ;
V_92 -> V_87 = F_93 ( V_6 , V_92 -> V_150 ,
V_88 , V_21 ) ;
if ( F_94 ( V_6 , V_92 -> V_87 ) ) {
F_50 ( V_6 , L_17 ) ;
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_88 = V_88 ;
return V_92 ;
}
static int F_95 ( struct V_93 * V_94 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_106 ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_87 ( V_94 , V_52 , & V_106 , true ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_78 ( V_94 , V_92 , V_106 , true ) ;
#ifdef F_31
F_33 ( V_63 , L_18 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_59 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static int F_99 ( struct V_93 * V_94 )
{
if ( V_94 -> V_119 < 8 )
return - V_47 ;
return F_95 ( V_94 ) ;
}
static int F_100 ( struct V_93 * V_94 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_106 ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_87 ( V_94 , V_46 ,
& V_106 , true ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_81 ( V_94 , V_92 , V_106 , true ) ;
#ifdef F_31
F_33 ( V_63 , L_18 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_59 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static int F_101 ( struct V_93 * V_94 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_106 ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_87 ( V_94 , V_52 , & V_106 , false ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_78 ( V_94 , V_92 , V_106 , false ) ;
#ifdef F_31
F_33 ( V_63 , L_18 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_63 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static int F_102 ( struct V_93 * V_94 )
{
if ( V_94 -> V_119 < 8 )
return - V_47 ;
return F_101 ( V_94 ) ;
}
static int F_103 ( struct V_93 * V_94 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 = F_70 ( V_94 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_106 ;
T_1 * V_7 ;
int V_61 = 0 ;
F_65 ( V_63 , L_19 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_94 -> V_82 ,
V_94 -> V_119 + V_94 -> V_120 , 1 ) ;
V_92 = F_87 ( V_94 , V_46 ,
& V_106 , false ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_81 ( V_94 , V_92 , V_106 , false ) ;
#ifdef F_31
F_33 ( V_63 , L_18 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_63 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_56 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static struct V_95 * F_104 ( struct V_96
* V_94 , int F_5 ,
bool * V_152 )
{
struct V_71 * V_72 = F_58 ( V_94 ) ;
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_140 = ( V_94 -> V_141 . V_140 & V_142 ) ?
V_143 : V_144 ;
int V_84 , V_145 , V_85 = 0 , V_146 = 0 ;
struct V_95 * V_92 ;
T_3 V_86 = 0 ;
bool V_153 ;
int V_27 = F_44 ( V_72 ) ;
int V_154 , V_155 , V_88 ;
V_84 = F_88 ( V_94 -> V_82 , V_94 -> V_105 ) ;
if ( F_75 ( V_84 < 0 ) ) {
F_50 ( V_6 , L_13 ,
V_94 -> V_105 ) ;
return F_89 ( V_84 ) ;
}
if ( V_94 -> V_83 != V_94 -> V_82 ) {
V_85 = F_88 ( V_94 -> V_83 , V_94 -> V_105 ) ;
if ( F_75 ( V_85 < 0 ) ) {
F_50 ( V_6 , L_14 ,
V_94 -> V_105 ) ;
return F_89 ( V_85 ) ;
}
}
if ( F_85 ( V_94 -> V_82 == V_94 -> V_83 ) ) {
V_145 = F_90 ( V_6 , V_94 -> V_82 , V_84 ,
V_90 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
} else {
V_145 = F_90 ( V_6 , V_94 -> V_82 , V_84 ,
V_21 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
V_146 = F_90 ( V_6 , V_94 -> V_83 , V_85 ,
V_89 ) ;
if ( F_75 ( ! V_146 ) ) {
F_50 ( V_6 , L_16 ) ;
F_54 ( V_6 , V_94 -> V_82 , V_84 , V_21 ) ;
return F_89 ( - V_148 ) ;
}
}
V_86 = F_93 ( V_6 , V_94 -> V_104 , V_27 , V_21 ) ;
if ( F_94 ( V_6 , V_86 ) ) {
F_50 ( V_6 , L_20 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 , 0 ,
0 , 0 , 0 ) ;
return F_89 ( - V_148 ) ;
}
if ( V_145 == 1 &&
V_86 + V_27 == F_73 ( V_94 -> V_82 ) ) {
V_153 = true ;
V_155 = 0 ;
} else {
V_153 = false ;
V_155 = 1 + V_145 ;
}
V_154 = V_155 ;
V_155 += V_146 > 1 ? V_146 : 0 ;
V_88 = V_155 * sizeof( struct V_121 ) ;
V_92 = F_91 ( sizeof( * V_92 ) + F_5 + V_88 ,
V_149 | V_140 ) ;
if ( ! V_92 ) {
F_50 ( V_6 , L_21 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 ,
V_86 , V_27 , 0 , 0 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_84 = V_84 ;
V_92 -> V_85 = V_85 ;
V_92 -> V_88 = V_88 ;
V_92 -> V_150 = ( void * ) V_92 + sizeof( struct V_95 ) +
F_5 ;
if ( ! V_153 ) {
F_105 ( V_92 -> V_150 , V_86 , V_27 , 0 ) ;
F_92 ( V_94 -> V_82 , V_145 ,
V_92 -> V_150 + 1 , 0 ) ;
}
if ( V_146 > 1 ) {
F_92 ( V_94 -> V_83 , V_146 ,
V_92 -> V_150 + V_154 , 0 ) ;
}
V_92 -> V_87 = F_93 ( V_6 , V_92 -> V_150 ,
V_88 , V_21 ) ;
if ( F_94 ( V_6 , V_92 -> V_87 ) ) {
F_50 ( V_6 , L_17 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 ,
V_86 , V_27 , 0 , 0 ) ;
F_61 ( V_92 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_86 = V_86 ;
#ifdef F_31
F_33 ( V_63 , L_22 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_150 ,
V_88 , 1 ) ;
#endif
* V_152 = V_153 ;
return V_92 ;
}
static int F_106 ( struct V_96 * V_94 )
{
struct V_95 * V_92 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_138 ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_104 ( V_94 , V_156 *
V_157 , & V_138 ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_83 ( V_4 -> V_18 ,
V_4 -> V_20 , V_92 , V_94 , V_138 ) ;
#ifdef F_31
F_33 ( V_63 , L_23 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_64 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_57 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static int F_107 ( struct V_96 * V_94 )
{
struct V_95 * V_92 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_138 ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_104 ( V_94 , V_156 *
V_157 , & V_138 ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_83 ( V_4 -> V_23 ,
V_4 -> V_24 , V_92 , V_94 , V_138 ) ;
V_7 = V_92 -> V_100 ;
#ifdef F_31
F_33 ( V_63 , L_23 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_61 = F_98 ( V_6 , V_7 , F_68 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_57 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static struct V_95 * F_108 (
struct V_158 * V_159 ,
int F_5 ,
bool * V_152 )
{
struct V_96 * V_94 = & V_159 -> V_160 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_140 = ( V_94 -> V_141 . V_140 & V_142 ) ?
V_143 : V_144 ;
int V_84 , V_145 , V_85 , V_146 ;
struct V_95 * V_92 ;
T_3 V_86 = 0 ;
bool V_161 ;
int V_27 = F_44 ( V_72 ) ;
int V_154 , V_155 , V_88 ;
V_84 = F_88 ( V_94 -> V_82 , V_94 -> V_105 ) ;
if ( F_75 ( V_84 < 0 ) ) {
F_50 ( V_6 , L_13 ,
V_94 -> V_105 ) ;
return F_89 ( V_84 ) ;
}
if ( F_85 ( V_94 -> V_82 == V_94 -> V_83 ) ) {
V_145 = F_90 ( V_6 , V_94 -> V_82 , V_84 ,
V_90 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
V_85 = V_84 ;
V_146 = V_84 ;
} else {
V_145 = F_90 ( V_6 , V_94 -> V_82 , V_84 ,
V_21 ) ;
if ( F_75 ( ! V_145 ) ) {
F_50 ( V_6 , L_15 ) ;
return F_89 ( - V_148 ) ;
}
V_85 = F_88 ( V_94 -> V_83 , V_94 -> V_105 ) ;
if ( F_75 ( V_85 < 0 ) ) {
F_50 ( V_6 , L_14 ,
V_94 -> V_105 ) ;
return F_89 ( V_85 ) ;
}
V_146 = F_90 ( V_6 , V_94 -> V_83 , V_85 ,
V_89 ) ;
if ( F_75 ( ! V_146 ) ) {
F_50 ( V_6 , L_16 ) ;
F_54 ( V_6 , V_94 -> V_82 , V_84 , V_21 ) ;
return F_89 ( - V_148 ) ;
}
}
V_86 = F_93 ( V_6 , V_159 -> V_162 , V_27 , V_21 ) ;
if ( F_94 ( V_6 , V_86 ) ) {
F_50 ( V_6 , L_20 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 , 0 ,
0 , 0 , 0 ) ;
return F_89 ( - V_148 ) ;
}
V_155 = V_145 > 1 ? V_145 : 0 ;
V_154 = V_155 ;
if ( V_146 == 1 &&
V_86 + V_27 == F_73 ( V_94 -> V_83 ) ) {
V_161 = true ;
} else {
V_161 = false ;
V_155 += 1 + V_146 ;
}
V_88 = V_155 * sizeof( struct V_121 ) ;
V_92 = F_91 ( sizeof( * V_92 ) + F_5 + V_88 ,
V_149 | V_140 ) ;
if ( ! V_92 ) {
F_50 ( V_6 , L_21 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 ,
V_86 , V_27 , 0 , 0 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_84 = V_84 ;
V_92 -> V_85 = V_85 ;
V_92 -> V_88 = V_88 ;
V_92 -> V_150 = ( void * ) V_92 + sizeof( struct V_95 ) +
F_5 ;
if ( V_145 > 1 )
F_92 ( V_94 -> V_82 , V_145 , V_92 -> V_150 ,
0 ) ;
if ( ! V_161 ) {
F_105 ( V_92 -> V_150 + V_154 ,
V_86 , V_27 , 0 ) ;
F_92 ( V_94 -> V_83 , V_146 ,
V_92 -> V_150 + V_154 + 1 , 0 ) ;
}
V_92 -> V_87 = F_93 ( V_6 , V_92 -> V_150 ,
V_88 , V_21 ) ;
if ( F_94 ( V_6 , V_92 -> V_87 ) ) {
F_50 ( V_6 , L_17 ) ;
F_53 ( V_6 , V_94 -> V_82 , V_94 -> V_83 , V_84 , V_85 ,
V_86 , V_27 , 0 , 0 ) ;
F_61 ( V_92 ) ;
return F_89 ( - V_148 ) ;
}
V_92 -> V_86 = V_86 ;
#ifdef F_31
F_33 ( V_63 ,
L_22 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_150 ,
V_88 , 1 ) ;
#endif
* V_152 = V_161 ;
return V_92 ;
}
static int F_109 ( struct V_158 * V_160 )
{
struct V_96 * V_94 = & V_160 -> V_160 ;
struct V_95 * V_92 ;
struct V_71 * V_72 = F_58 ( V_94 ) ;
struct V_3 * V_4 = F_41 ( V_72 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
bool V_138 = false ;
T_1 * V_7 ;
int V_61 = 0 ;
V_92 = F_108 ( V_160 , V_156 *
V_157 , & V_138 ) ;
if ( F_96 ( V_92 ) )
return F_97 ( V_92 ) ;
F_86 ( V_4 -> V_76 , V_4 -> V_77 ,
V_92 , V_94 , V_138 ) ;
#ifdef F_31
F_33 ( V_63 ,
L_23 F_34 ( __LINE__ ) L_3 ,
V_66 , 16 , 4 , V_92 -> V_100 ,
F_5 ( V_92 -> V_100 ) , 1 ) ;
#endif
V_7 = V_92 -> V_100 ;
V_61 = F_98 ( V_6 , V_7 , F_64 , V_94 ) ;
if ( ! V_61 ) {
V_61 = - V_151 ;
} else {
F_57 ( V_6 , V_92 , V_94 ) ;
F_61 ( V_92 ) ;
}
return V_61 ;
}
static int F_110 ( struct V_3 * V_4 , struct V_163 * V_38 )
{
T_3 V_164 ;
V_4 -> V_6 = F_111 () ;
if ( F_96 ( V_4 -> V_6 ) ) {
F_84 ( L_24 ) ;
return F_97 ( V_4 -> V_6 ) ;
}
V_164 = F_112 ( V_4 -> V_6 , V_4 -> V_18 ,
F_113 ( struct V_3 ,
V_20 ) ,
V_21 , V_165 ) ;
if ( F_94 ( V_4 -> V_6 , V_164 ) ) {
F_50 ( V_4 -> V_6 , L_25 ) ;
F_114 ( V_4 -> V_6 ) ;
return - V_148 ;
}
V_4 -> V_20 = V_164 ;
V_4 -> V_24 = V_164 + F_113 ( struct V_3 ,
V_23 ) ;
V_4 -> V_77 = V_164 + F_113 ( struct V_3 ,
V_76 ) ;
V_4 -> V_17 = V_164 + F_113 ( struct V_3 , V_16 ) ;
V_4 -> V_33 . V_34 = V_166 | V_38 -> V_167 ;
V_4 -> V_11 . V_34 = V_168 | V_38 -> V_169 ;
return 0 ;
}
static int F_115 ( struct V_73 * V_74 )
{
struct V_170 * V_26 = V_74 -> V_171 ;
struct V_172 * V_173 =
F_8 ( V_26 , struct V_172 , V_170 ) ;
struct V_3 * V_4 = F_116 ( V_74 ) ;
return F_110 ( V_4 , & V_173 -> V_38 ) ;
}
static int F_117 ( struct V_1 * V_74 )
{
struct V_174 * V_26 = F_9 ( V_74 ) ;
struct V_25 * V_173 =
F_8 ( V_26 , struct V_25 , V_2 ) ;
struct V_3 * V_4 = F_2 ( V_74 ) ;
return F_110 ( V_4 , & V_173 -> V_38 ) ;
}
static void F_118 ( struct V_3 * V_4 )
{
F_119 ( V_4 -> V_6 , V_4 -> V_20 ,
F_113 ( struct V_3 , V_20 ) ,
V_21 , V_165 ) ;
F_114 ( V_4 -> V_6 ) ;
}
static void F_120 ( struct V_73 * V_74 )
{
F_118 ( F_116 ( V_74 ) ) ;
}
static void F_121 ( struct V_1 * V_74 )
{
F_118 ( F_2 ( V_74 ) ) ;
}
static void T_5 F_122 ( void )
{
struct V_172 * V_175 , * V_176 ;
int V_177 ;
for ( V_177 = 0 ; V_177 < F_12 ( V_178 ) ; V_177 ++ ) {
struct V_25 * V_175 = V_178 + V_177 ;
if ( V_175 -> V_179 )
F_123 ( & V_175 -> V_2 ) ;
}
if ( ! V_180 . V_181 )
return;
F_124 (t_alg, n, &alg_list, entry) {
F_125 ( & V_175 -> V_170 ) ;
F_126 ( & V_175 -> V_182 ) ;
F_61 ( V_175 ) ;
}
}
static struct V_172 * F_127 ( struct V_183
* V_184 )
{
struct V_172 * V_175 ;
struct V_170 * V_26 ;
V_175 = F_91 ( sizeof( * V_175 ) , V_143 ) ;
if ( ! V_175 ) {
F_84 ( L_26 ) ;
return F_89 ( - V_148 ) ;
}
V_26 = & V_175 -> V_170 ;
snprintf ( V_26 -> V_185 , V_186 , L_27 , V_184 -> V_187 ) ;
snprintf ( V_26 -> V_188 , V_186 , L_27 ,
V_184 -> V_189 ) ;
V_26 -> V_190 = V_191 ;
V_26 -> V_192 = F_115 ;
V_26 -> V_193 = F_120 ;
V_26 -> V_194 = V_195 ;
V_26 -> V_196 = V_184 -> V_197 ;
V_26 -> V_198 = 0 ;
V_26 -> V_199 = sizeof( struct V_3 ) ;
V_26 -> V_200 = V_201 | V_202 |
V_184 -> type ;
switch ( V_184 -> type ) {
case V_203 :
V_26 -> V_204 = & V_205 ;
V_26 -> V_206 = V_184 -> V_207 ;
break;
case V_208 :
V_26 -> V_204 = & V_209 ;
V_26 -> V_206 = V_184 -> V_207 ;
break;
}
V_175 -> V_38 . V_167 = V_184 -> V_167 ;
V_175 -> V_38 . V_169 = V_184 -> V_169 ;
return V_175 ;
}
static void F_128 ( struct V_25 * V_175 )
{
struct V_174 * V_26 = & V_175 -> V_2 ;
V_26 -> V_141 . V_190 = V_191 ;
V_26 -> V_141 . V_194 = V_195 ;
V_26 -> V_141 . V_199 = sizeof( struct V_3 ) ;
V_26 -> V_141 . V_200 = V_201 | V_202 ;
V_26 -> V_210 = F_117 ;
V_26 -> exit = F_121 ;
}
static int T_6 F_129 ( void )
{
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_5 * V_215 ;
struct V_216 * V_217 ;
int V_177 = 0 , V_97 = 0 ;
T_1 V_218 , V_219 , V_220 , V_221 , V_222 ;
unsigned int V_223 = V_224 ;
bool V_179 = false ;
V_212 = F_130 ( NULL , NULL , L_28 ) ;
if ( ! V_212 ) {
V_212 = F_130 ( NULL , NULL , L_29 ) ;
if ( ! V_212 )
return - V_225 ;
}
V_214 = F_131 ( V_212 ) ;
if ( ! V_214 ) {
F_132 ( V_212 ) ;
return - V_225 ;
}
V_215 = & V_214 -> V_80 ;
V_217 = F_133 ( V_215 ) ;
F_132 ( V_212 ) ;
if ( ! V_217 )
return - V_225 ;
F_134 ( & V_180 ) ;
V_218 = F_135 ( & V_217 -> V_226 -> V_227 . V_228 ) ;
V_219 = F_135 ( & V_217 -> V_226 -> V_227 . V_229 ) ;
V_220 = ( V_219 & V_230 ) >> V_231 ;
V_221 = ( V_219 & V_232 ) >> V_233 ;
V_222 = ( V_219 & V_234 ) >> V_235 ;
if ( V_222 && ( ( V_218 & V_234 ) == V_236 ) )
V_223 = V_237 ;
for ( V_177 = 0 ; V_177 < F_12 ( V_238 ) ; V_177 ++ ) {
struct V_172 * V_175 ;
struct V_183 * V_26 = V_238 + V_177 ;
T_1 V_239 = V_26 -> V_167 & V_240 ;
if ( ! V_220 &&
( ( V_239 == V_241 ) ||
( V_239 == V_242 ) ) )
continue;
if ( ! V_221 && ( V_239 == V_243 ) )
continue;
if ( ( V_218 & V_232 ) == V_244 )
if ( ( V_26 -> V_167 & V_35 ) ==
V_245 )
continue;
V_175 = F_127 ( V_26 ) ;
if ( F_96 ( V_175 ) ) {
V_97 = F_97 ( V_175 ) ;
F_136 ( L_30 , V_26 -> V_189 ) ;
continue;
}
V_97 = F_137 ( & V_175 -> V_170 ) ;
if ( V_97 ) {
F_136 ( L_31 ,
V_175 -> V_170 . V_188 ) ;
F_61 ( V_175 ) ;
continue;
}
F_138 ( & V_175 -> V_182 , & V_180 ) ;
V_179 = true ;
}
for ( V_177 = 0 ; V_177 < F_12 ( V_178 ) ; V_177 ++ ) {
struct V_25 * V_175 = V_178 + V_177 ;
T_1 V_246 = V_175 -> V_38 . V_167 &
V_240 ;
T_1 V_247 = V_175 -> V_38 . V_169 &
V_240 ;
T_1 V_248 = V_175 -> V_38 . V_167 & V_35 ;
if ( ! V_220 &&
( ( V_246 == V_241 ) ||
( V_246 == V_242 ) ) )
continue;
if ( ! V_221 && ( V_246 == V_243 ) )
continue;
if ( ( V_218 & V_232 ) == V_244 )
if ( V_248 == V_249 )
continue;
if ( V_247 &&
( ! V_222 || ( V_175 -> V_2 . V_250 > V_223 ) ) )
continue;
F_128 ( V_175 ) ;
V_97 = F_139 ( & V_175 -> V_2 ) ;
if ( V_97 ) {
F_136 ( L_31 ,
V_175 -> V_2 . V_141 . V_188 ) ;
continue;
}
V_175 -> V_179 = true ;
V_179 = true ;
}
if ( V_179 )
F_140 ( L_32 ) ;
return V_97 ;
}

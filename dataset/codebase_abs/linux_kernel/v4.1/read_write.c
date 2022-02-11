static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
T_1 F_2 ( struct V_1 * V_1 , T_1 V_4 , T_1 V_5 )
{
if ( V_4 < 0 && ! F_1 ( V_1 ) )
return - V_6 ;
if ( V_4 > V_5 )
return - V_6 ;
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
return V_4 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_9 ,
T_1 V_5 , T_1 V_10 )
{
switch ( V_9 ) {
case V_11 :
V_4 += V_10 ;
break;
case V_12 :
if ( V_4 == 0 )
return V_1 -> V_7 ;
F_4 ( & V_1 -> V_13 ) ;
V_4 = F_2 ( V_1 , V_1 -> V_7 + V_4 , V_5 ) ;
F_5 ( & V_1 -> V_13 ) ;
return V_4 ;
case V_14 :
if ( V_4 >= V_10 )
return - V_15 ;
break;
case V_16 :
if ( V_4 >= V_10 )
return - V_15 ;
V_4 = V_10 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = V_1 -> V_18 -> V_19 ;
return F_3 ( V_1 , V_4 , V_9 ,
V_17 -> V_20 -> V_21 ,
F_7 ( V_17 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_4 , int V_9 , T_1 V_22 )
{
switch ( V_9 ) {
case V_23 : case V_12 : case V_11 :
return F_3 ( V_1 , V_4 , V_9 ,
V_22 , V_22 ) ;
default:
return - V_6 ;
}
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return V_1 -> V_7 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return - V_24 ;
}
T_1 F_11 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = F_12 ( V_1 ) ;
T_1 V_25 ;
F_13 ( & V_17 -> V_26 ) ;
switch ( V_9 ) {
case V_11 :
V_4 += F_7 ( V_17 ) ;
break;
case V_12 :
if ( V_4 == 0 ) {
V_25 = V_1 -> V_7 ;
goto V_27;
}
V_4 += V_1 -> V_7 ;
break;
case V_14 :
if ( V_4 >= V_17 -> V_28 ) {
V_25 = - V_15 ;
goto V_27;
}
break;
case V_16 :
if ( V_4 >= V_17 -> V_28 ) {
V_25 = - V_15 ;
goto V_27;
}
V_4 = V_17 -> V_28 ;
break;
}
V_25 = - V_6 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
V_25 = V_4 ;
}
V_27:
F_14 ( & V_17 -> V_26 ) ;
return V_25 ;
}
T_1 F_15 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
T_1 (* F_16)( struct V_1 * , T_1 , int );
F_16 = F_10 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 -> V_31 )
F_16 = V_1 -> V_30 -> V_31 ;
}
return F_16 ( V_1 , V_4 , V_9 ) ;
}
static inline struct V_32 F_17 ( int V_32 )
{
return F_18 ( F_19 ( V_32 ) ) ;
}
static inline void F_20 ( struct V_32 V_33 )
{
if ( V_33 . V_34 & V_35 )
F_14 ( & V_33 . V_1 -> V_36 ) ;
F_21 ( V_33 ) ;
}
T_2 F_22 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_42 )
return - V_6 ;
F_23 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_44 ;
V_41 = V_1 -> V_30 -> V_42 ( & V_40 , V_38 ) ;
F_24 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_25 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_46 )
return - V_6 ;
F_23 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_47 ;
V_41 = V_1 -> V_30 -> V_46 ( & V_40 , V_38 ) ;
F_24 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
int F_26 ( int V_48 , struct V_1 * V_1 , const T_1 * V_39 , T_3 V_49 )
{
struct V_17 * V_17 ;
T_1 V_50 ;
int V_25 = - V_6 ;
V_17 = F_12 ( V_1 ) ;
if ( F_27 ( ( T_2 ) V_49 < 0 ) )
return V_25 ;
V_50 = * V_39 ;
if ( F_27 ( V_50 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_49 >= - V_50 )
return - V_51 ;
} else if ( F_27 ( ( T_1 ) ( V_50 + V_49 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_27 ( V_17 -> V_52 && F_28 ( V_17 ) ) ) {
V_25 = F_29 (
V_48 == V_44 ? V_53 : V_54 ,
V_17 , V_1 , V_50 , V_49 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_30 ( V_1 ,
V_48 == V_44 ? V_55 : V_56 ) ;
if ( V_25 )
return V_25 ;
return V_49 > V_57 ? V_57 : V_49 ;
}
static T_2 F_31 ( struct V_1 * V_58 , char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_23 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_32 ( & V_38 , V_44 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_42 ( & V_40 , & V_38 ) ;
F_24 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_33 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_65 )
return V_1 -> V_30 -> V_65 ( V_1 , V_59 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_42 )
return F_31 ( V_1 , V_59 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_34 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
if ( F_27 ( ! F_35 ( V_69 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_26 ( V_44 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
V_41 = F_33 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_36 ( V_1 ) ;
F_37 ( V_71 , V_41 ) ;
}
F_38 ( V_71 ) ;
}
return V_41 ;
}
static T_2 F_39 ( struct V_1 * V_58 , const char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = ( void T_4 * ) V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_23 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_32 ( & V_38 , V_47 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_46 ( & V_40 , & V_38 ) ;
F_24 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_40 ( struct V_1 * V_1 , const char T_4 * V_72 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_73 )
return V_1 -> V_30 -> V_73 ( V_1 , V_72 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_46 )
return F_39 ( V_1 , V_72 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_41 ( struct V_1 * V_1 , const char * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_5 V_74 ;
const char T_4 * V_72 ;
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
V_74 = F_42 () ;
F_43 ( F_44 () ) ;
V_72 = ( V_76 const char T_4 * ) V_59 ;
if ( V_49 > V_57 )
V_49 = V_57 ;
V_41 = F_40 ( V_1 , V_72 , V_49 , V_50 ) ;
F_43 ( V_74 ) ;
if ( V_41 > 0 ) {
F_45 ( V_1 ) ;
F_46 ( V_71 , V_41 ) ;
}
F_47 ( V_71 ) ;
return V_41 ;
}
T_2 F_48 ( struct V_1 * V_1 , const char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
if ( F_27 ( ! F_35 ( V_78 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_26 ( V_47 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
F_49 ( V_1 ) ;
V_41 = F_40 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_45 ( V_1 ) ;
F_46 ( V_71 , V_41 ) ;
}
F_47 ( V_71 ) ;
F_50 ( V_1 ) ;
}
return V_41 ;
}
static inline T_1 F_51 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_52 ( struct V_1 * V_1 , T_1 V_50 )
{
V_1 -> V_7 = V_50 ;
}
unsigned long F_53 ( struct V_61 * V_62 , unsigned long V_79 , T_3 V_80 )
{
unsigned long V_81 = 0 ;
T_3 V_60 = 0 ;
while ( V_81 < V_79 ) {
V_81 ++ ;
if ( V_60 + V_62 -> V_64 >= V_80 ) {
V_62 -> V_64 = V_80 - V_60 ;
break;
}
V_60 += V_62 -> V_64 ;
V_62 ++ ;
}
return V_81 ;
}
static T_2 F_54 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_6 F_16 )
{
struct V_40 V_40 ;
T_2 V_41 ;
F_23 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
V_41 = F_16 ( & V_40 , V_38 ) ;
F_24 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
static T_2 F_55 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_7 F_16 )
{
T_2 V_41 = 0 ;
while ( F_56 ( V_38 ) ) {
struct V_61 V_61 = F_57 ( V_38 ) ;
T_2 V_82 ;
V_82 = F_16 ( V_58 , V_61 . V_63 , V_61 . V_64 , V_39 ) ;
if ( V_82 < 0 ) {
if ( ! V_41 )
V_41 = V_82 ;
break;
}
V_41 += V_82 ;
if ( V_82 != V_61 . V_64 )
break;
F_58 ( V_38 , V_82 ) ;
}
return V_41 ;
}
T_2 F_59 ( int type , const struct V_61 T_4 * V_83 ,
unsigned long V_79 , unsigned long V_84 ,
struct V_61 * V_85 ,
struct V_61 * * V_86 )
{
unsigned long V_81 ;
T_2 V_41 ;
struct V_61 * V_62 = V_85 ;
if ( V_79 == 0 ) {
V_41 = 0 ;
goto V_27;
}
if ( V_79 > V_87 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( V_79 > V_84 ) {
V_62 = F_60 ( V_79 * sizeof( struct V_61 ) , V_88 ) ;
if ( V_62 == NULL ) {
V_41 = - V_89 ;
goto V_27;
}
}
if ( F_61 ( V_62 , V_83 , V_79 * sizeof( * V_83 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
V_41 = 0 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
void T_4 * V_59 = V_62 [ V_81 ] . V_63 ;
T_2 V_60 = ( T_2 ) V_62 [ V_81 ] . V_64 ;
if ( V_60 < 0 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_27 ( ! F_35 ( F_62 ( type ) , V_59 , V_60 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
if ( V_60 > V_57 - V_41 ) {
V_60 = V_57 - V_41 ;
V_62 [ V_81 ] . V_64 = V_60 ;
}
V_41 += V_60 ;
}
V_27:
* V_86 = V_62 ;
return V_41 ;
}
static T_2 F_63 ( int type , struct V_1 * V_1 ,
const struct V_61 T_4 * V_83 ,
unsigned long V_79 , T_1 * V_50 )
{
T_3 V_90 ;
struct V_61 V_91 [ V_92 ] ;
struct V_61 * V_62 = V_91 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_16 ;
T_6 V_93 ;
V_41 = F_64 ( type , V_83 , V_79 ,
F_65 ( V_91 ) , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_90 = F_56 ( & V_38 ) ;
if ( ! V_90 )
goto V_27;
V_41 = F_26 ( type , V_1 , V_50 , V_90 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_16 = V_1 -> V_30 -> V_65 ;
V_93 = V_1 -> V_30 -> V_42 ;
} else {
F_16 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_93 = V_1 -> V_30 -> V_46 ;
F_49 ( V_1 ) ;
}
if ( V_93 )
V_41 = F_54 ( V_1 , & V_38 , V_50 , V_93 ) ;
else
V_41 = F_55 ( V_1 , & V_38 , V_50 , F_16 ) ;
if ( type != V_44 )
F_50 ( V_1 ) ;
V_27:
F_66 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_36 ( V_1 ) ;
else
F_45 ( V_1 ) ;
}
return V_41 ;
}
T_2 F_67 ( struct V_1 * V_1 , const struct V_61 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
return F_63 ( V_44 , V_1 , V_94 , V_95 , V_50 ) ;
}
T_2 F_68 ( struct V_1 * V_1 , const struct V_61 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
return F_63 ( V_47 , V_1 , V_94 , V_95 , V_50 ) ;
}
static inline T_1 F_69 ( unsigned long V_96 , unsigned long V_97 )
{
#define F_70 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_96 << F_70 ) << F_70 ) | V_97 ;
}
static T_2 F_71 ( int type , struct V_1 * V_1 ,
const struct V_98 T_4 * V_83 ,
unsigned long V_79 , T_1 * V_50 )
{
T_8 V_90 ;
struct V_61 V_91 [ V_92 ] ;
struct V_61 * V_62 = V_91 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_16 ;
T_6 V_93 ;
V_41 = F_72 ( type , V_83 , V_79 ,
V_92 , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_90 = F_56 ( & V_38 ) ;
if ( ! V_90 )
goto V_27;
V_41 = F_26 ( type , V_1 , V_50 , V_90 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_16 = V_1 -> V_30 -> V_65 ;
V_93 = V_1 -> V_30 -> V_42 ;
} else {
F_16 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_93 = V_1 -> V_30 -> V_46 ;
F_49 ( V_1 ) ;
}
if ( V_93 )
V_41 = F_54 ( V_1 , & V_38 , V_50 , V_93 ) ;
else
V_41 = F_55 ( V_1 , & V_38 , V_50 , F_16 ) ;
if ( type != V_44 )
F_50 ( V_1 ) ;
V_27:
F_66 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_36 ( V_1 ) ;
else
F_45 ( V_1 ) ;
}
return V_41 ;
}
static T_3 F_73 ( struct V_1 * V_1 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
goto V_27;
V_41 = F_71 ( V_44 , V_1 , V_94 , V_95 , V_50 ) ;
V_27:
if ( V_41 > 0 )
F_37 ( V_71 , V_41 ) ;
F_38 ( V_71 ) ;
return V_41 ;
}
static long F_74 ( unsigned long V_32 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 V_50 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_75 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_99 )
V_41 = F_73 ( V_33 . V_1 , V_94 , V_95 , & V_50 ) ;
F_21 ( V_33 ) ;
return V_41 ;
}
static T_3 F_76 ( struct V_1 * V_1 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
goto V_27;
V_41 = F_71 ( V_47 , V_1 , V_94 , V_95 , V_50 ) ;
V_27:
if ( V_41 > 0 )
F_46 ( V_71 , V_41 ) ;
F_47 ( V_71 ) ;
return V_41 ;
}
static long F_77 ( unsigned long V_32 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 V_50 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_75 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_100 )
V_41 = F_76 ( V_33 . V_1 , V_94 , V_95 , & V_50 ) ;
F_21 ( V_33 ) ;
return V_41 ;
}
static T_2 F_78 ( int V_101 , int V_102 , T_1 * V_39 ,
T_3 V_49 , T_1 V_103 )
{
struct V_32 V_104 , V_27 ;
struct V_17 * V_105 , * V_106 ;
T_1 V_50 ;
T_1 V_107 ;
T_2 V_25 ;
int V_108 ;
V_25 = - V_67 ;
V_104 = F_75 ( V_102 ) ;
if ( ! V_104 . V_1 )
goto V_27;
if ( ! ( V_104 . V_1 -> V_2 & V_66 ) )
goto V_109;
V_25 = - V_24 ;
if ( ! V_39 ) {
V_50 = V_104 . V_1 -> V_7 ;
} else {
V_50 = * V_39 ;
if ( ! ( V_104 . V_1 -> V_2 & V_99 ) )
goto V_109;
}
V_25 = F_26 ( V_44 , V_104 . V_1 , & V_50 , V_49 ) ;
if ( V_25 < 0 )
goto V_109;
V_49 = V_25 ;
V_25 = - V_67 ;
V_27 = F_75 ( V_101 ) ;
if ( ! V_27 . V_1 )
goto V_109;
if ( ! ( V_27 . V_1 -> V_2 & V_77 ) )
goto V_110;
V_25 = - V_6 ;
V_105 = F_12 ( V_104 . V_1 ) ;
V_106 = F_12 ( V_27 . V_1 ) ;
V_107 = V_27 . V_1 -> V_7 ;
V_25 = F_26 ( V_47 , V_27 . V_1 , & V_107 , V_49 ) ;
if ( V_25 < 0 )
goto V_110;
V_49 = V_25 ;
if ( ! V_103 )
V_103 = F_79 ( V_105 -> V_20 -> V_21 , V_106 -> V_20 -> V_21 ) ;
if ( F_27 ( V_50 + V_49 > V_103 ) ) {
V_25 = - V_51 ;
if ( V_50 >= V_103 )
goto V_110;
V_49 = V_103 - V_50 ;
}
V_108 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_49 ( V_27 . V_1 ) ;
V_25 = F_80 ( V_104 . V_1 , & V_50 , V_27 . V_1 , & V_107 , V_49 , V_108 ) ;
F_50 ( V_27 . V_1 ) ;
if ( V_25 > 0 ) {
F_37 ( V_71 , V_25 ) ;
F_46 ( V_71 , V_25 ) ;
F_36 ( V_104 . V_1 ) ;
F_45 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_107 ;
if ( V_39 )
* V_39 = V_50 ;
else
V_104 . V_1 -> V_7 = V_50 ;
}
F_38 ( V_71 ) ;
F_47 ( V_71 ) ;
if ( V_50 > V_103 )
V_25 = - V_51 ;
V_110:
F_21 ( V_27 ) ;
V_109:
F_21 ( V_104 ) ;
V_27:
return V_25 ;
}

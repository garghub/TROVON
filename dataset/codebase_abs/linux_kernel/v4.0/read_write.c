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
V_40 . V_44 = F_24 ( V_38 ) ;
V_38 -> type |= V_45 ;
V_41 = V_1 -> V_30 -> V_42 ( & V_40 , V_38 ) ;
if ( V_41 == - V_46 )
V_41 = F_25 ( & V_40 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_26 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_47 )
return - V_6 ;
F_23 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = F_24 ( V_38 ) ;
V_38 -> type |= V_48 ;
V_41 = V_1 -> V_30 -> V_47 ( & V_40 , V_38 ) ;
if ( V_41 == - V_46 )
V_41 = F_25 ( & V_40 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
int F_27 ( int V_49 , struct V_1 * V_1 , const T_1 * V_39 , T_3 V_50 )
{
struct V_17 * V_17 ;
T_1 V_51 ;
int V_25 = - V_6 ;
V_17 = F_12 ( V_1 ) ;
if ( F_28 ( ( T_2 ) V_50 < 0 ) )
return V_25 ;
V_51 = * V_39 ;
if ( F_28 ( V_51 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_50 >= - V_51 )
return - V_52 ;
} else if ( F_28 ( ( T_1 ) ( V_51 + V_50 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_28 ( V_17 -> V_53 && F_29 ( V_17 ) ) ) {
V_25 = F_30 (
V_49 == V_45 ? V_54 : V_55 ,
V_17 , V_1 , V_51 , V_50 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_31 ( V_1 ,
V_49 == V_45 ? V_56 : V_57 ) ;
if ( V_25 )
return V_25 ;
return V_50 > V_58 ? V_58 : V_50 ;
}
T_2 F_32 ( struct V_1 * V_59 , char T_4 * V_60 , T_3 V_61 , T_1 * V_39 )
{
struct V_62 V_63 = { . V_64 = V_60 , . V_65 = V_61 } ;
struct V_40 V_40 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
V_41 = V_59 -> V_30 -> V_66 ( & V_40 , & V_63 , 1 , V_40 . V_43 ) ;
if ( - V_46 == V_41 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_33 ( struct V_1 * V_59 , char T_4 * V_60 , T_3 V_61 , T_1 * V_39 )
{
struct V_62 V_63 = { . V_64 = V_60 , . V_65 = V_61 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
F_34 ( & V_38 , V_45 , & V_63 , 1 , V_61 ) ;
V_41 = V_59 -> V_30 -> V_42 ( & V_40 , & V_38 ) ;
if ( - V_46 == V_41 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_35 ( struct V_1 * V_1 , char T_4 * V_60 , T_3 V_50 ,
T_1 * V_51 )
{
T_2 V_41 ;
if ( V_1 -> V_30 -> V_67 )
V_41 = V_1 -> V_30 -> V_67 ( V_1 , V_60 , V_50 , V_51 ) ;
else if ( V_1 -> V_30 -> V_66 )
V_41 = F_32 ( V_1 , V_60 , V_50 , V_51 ) ;
else if ( V_1 -> V_30 -> V_42 )
V_41 = F_33 ( V_1 , V_60 , V_50 , V_51 ) ;
else
V_41 = - V_6 ;
return V_41 ;
}
T_2 F_36 ( struct V_1 * V_1 , char T_4 * V_60 , T_3 V_50 , T_1 * V_51 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_69 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
if ( F_28 ( ! F_37 ( V_71 , V_60 , V_50 ) ) )
return - V_72 ;
V_41 = F_27 ( V_45 , V_1 , V_51 , V_50 ) ;
if ( V_41 >= 0 ) {
V_50 = V_41 ;
V_41 = F_35 ( V_1 , V_60 , V_50 , V_51 ) ;
if ( V_41 > 0 ) {
F_38 ( V_1 ) ;
F_39 ( V_73 , V_41 ) ;
}
F_40 ( V_73 ) ;
}
return V_41 ;
}
T_2 F_41 ( struct V_1 * V_59 , const char T_4 * V_60 , T_3 V_61 , T_1 * V_39 )
{
struct V_62 V_63 = { . V_64 = ( void T_4 * ) V_60 , . V_65 = V_61 } ;
struct V_40 V_40 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
V_41 = V_59 -> V_30 -> V_74 ( & V_40 , & V_63 , 1 , V_40 . V_43 ) ;
if ( - V_46 == V_41 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_42 ( struct V_1 * V_59 , const char T_4 * V_60 , T_3 V_61 , T_1 * V_39 )
{
struct V_62 V_63 = { . V_64 = ( void T_4 * ) V_60 , . V_65 = V_61 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
F_34 ( & V_38 , V_48 , & V_63 , 1 , V_61 ) ;
V_41 = V_59 -> V_30 -> V_47 ( & V_40 , & V_38 ) ;
if ( - V_46 == V_41 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_43 ( struct V_1 * V_1 , const char * V_60 , T_3 V_50 , T_1 * V_51 )
{
T_5 V_75 ;
const char T_4 * V_76 ;
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_6 ;
V_75 = F_44 () ;
F_45 ( F_46 () ) ;
V_76 = ( V_78 const char T_4 * ) V_60 ;
if ( V_50 > V_58 )
V_50 = V_58 ;
if ( V_1 -> V_30 -> V_79 )
V_41 = V_1 -> V_30 -> V_79 ( V_1 , V_76 , V_50 , V_51 ) ;
else if ( V_1 -> V_30 -> V_74 )
V_41 = F_41 ( V_1 , V_76 , V_50 , V_51 ) ;
else
V_41 = F_42 ( V_1 , V_76 , V_50 , V_51 ) ;
F_45 ( V_75 ) ;
if ( V_41 > 0 ) {
F_47 ( V_1 ) ;
F_48 ( V_73 , V_41 ) ;
}
F_49 ( V_73 ) ;
return V_41 ;
}
T_2 F_50 ( struct V_1 * V_1 , const char T_4 * V_60 , T_3 V_50 , T_1 * V_51 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_80 ) )
return - V_69 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_6 ;
if ( F_28 ( ! F_37 ( V_81 , V_60 , V_50 ) ) )
return - V_72 ;
V_41 = F_27 ( V_48 , V_1 , V_51 , V_50 ) ;
if ( V_41 >= 0 ) {
V_50 = V_41 ;
F_51 ( V_1 ) ;
if ( V_1 -> V_30 -> V_79 )
V_41 = V_1 -> V_30 -> V_79 ( V_1 , V_60 , V_50 , V_51 ) ;
else if ( V_1 -> V_30 -> V_74 )
V_41 = F_41 ( V_1 , V_60 , V_50 , V_51 ) ;
else
V_41 = F_42 ( V_1 , V_60 , V_50 , V_51 ) ;
if ( V_41 > 0 ) {
F_47 ( V_1 ) ;
F_48 ( V_73 , V_41 ) ;
}
F_49 ( V_73 ) ;
F_52 ( V_1 ) ;
}
return V_41 ;
}
static inline T_1 F_53 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_54 ( struct V_1 * V_1 , T_1 V_51 )
{
V_1 -> V_7 = V_51 ;
}
unsigned long F_55 ( struct V_62 * V_63 , unsigned long V_82 , T_3 V_83 )
{
unsigned long V_84 = 0 ;
T_3 V_61 = 0 ;
while ( V_84 < V_82 ) {
V_84 ++ ;
if ( V_61 + V_63 -> V_65 >= V_83 ) {
V_63 -> V_65 = V_83 - V_61 ;
break;
}
V_61 += V_63 -> V_65 ;
V_63 ++ ;
}
return V_84 ;
}
static T_2 F_56 ( struct V_1 * V_59 , int V_85 , const struct V_62 * V_63 ,
unsigned long V_82 , T_3 V_61 , T_1 * V_39 , T_6 F_16 )
{
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
F_34 ( & V_38 , V_85 , V_63 , V_82 , V_61 ) ;
V_41 = F_16 ( & V_40 , & V_38 ) ;
if ( V_41 == - V_46 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
static T_2 F_57 ( struct V_1 * V_59 , const struct V_62 * V_63 ,
unsigned long V_82 , T_3 V_61 , T_1 * V_39 , T_7 F_16 )
{
struct V_40 V_40 ;
T_2 V_41 ;
F_23 ( & V_40 , V_59 ) ;
V_40 . V_43 = * V_39 ;
V_40 . V_44 = V_61 ;
V_41 = F_16 ( & V_40 , V_63 , V_82 , V_40 . V_43 ) ;
if ( V_41 == - V_46 )
V_41 = F_25 ( & V_40 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
static T_2 F_58 ( struct V_1 * V_59 , struct V_62 * V_63 ,
unsigned long V_82 , T_1 * V_39 , T_8 F_16 )
{
struct V_62 * V_86 = V_63 ;
T_2 V_41 = 0 ;
while ( V_82 > 0 ) {
void T_4 * V_87 ;
T_3 V_61 ;
T_2 V_88 ;
V_87 = V_86 -> V_64 ;
V_61 = V_86 -> V_65 ;
V_86 ++ ;
V_82 -- ;
V_88 = F_16 ( V_59 , V_87 , V_61 , V_39 ) ;
if ( V_88 < 0 ) {
if ( ! V_41 )
V_41 = V_88 ;
break;
}
V_41 += V_88 ;
if ( V_88 != V_61 )
break;
}
return V_41 ;
}
T_2 F_59 ( int type , const struct V_62 T_4 * V_89 ,
unsigned long V_82 , unsigned long V_90 ,
struct V_62 * V_91 ,
struct V_62 * * V_92 )
{
unsigned long V_84 ;
T_2 V_41 ;
struct V_62 * V_63 = V_91 ;
if ( V_82 == 0 ) {
V_41 = 0 ;
goto V_27;
}
if ( V_82 > V_93 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( V_82 > V_90 ) {
V_63 = F_60 ( V_82 * sizeof( struct V_62 ) , V_94 ) ;
if ( V_63 == NULL ) {
V_41 = - V_95 ;
goto V_27;
}
}
if ( F_61 ( V_63 , V_89 , V_82 * sizeof( * V_89 ) ) ) {
V_41 = - V_72 ;
goto V_27;
}
V_41 = 0 ;
for ( V_84 = 0 ; V_84 < V_82 ; V_84 ++ ) {
void T_4 * V_60 = V_63 [ V_84 ] . V_64 ;
T_2 V_61 = ( T_2 ) V_63 [ V_84 ] . V_65 ;
if ( V_61 < 0 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_28 ( ! F_37 ( F_62 ( type ) , V_60 , V_61 ) ) ) {
V_41 = - V_72 ;
goto V_27;
}
if ( V_61 > V_58 - V_41 ) {
V_61 = V_58 - V_41 ;
V_63 [ V_84 ] . V_65 = V_61 ;
}
V_41 += V_61 ;
}
V_27:
* V_92 = V_63 ;
return V_41 ;
}
static T_2 F_63 ( int type , struct V_1 * V_1 ,
const struct V_62 T_4 * V_89 ,
unsigned long V_82 , T_1 * V_51 )
{
T_3 V_96 ;
struct V_62 V_97 [ V_98 ] ;
struct V_62 * V_63 = V_97 ;
T_2 V_41 ;
T_8 F_16 ;
T_7 V_99 ;
T_6 V_100 ;
V_41 = F_59 ( type , V_89 , V_82 ,
F_64 ( V_97 ) , V_97 , & V_63 ) ;
if ( V_41 <= 0 )
goto V_27;
V_96 = V_41 ;
V_41 = F_27 ( type , V_1 , V_51 , V_96 ) ;
if ( V_41 < 0 )
goto V_27;
V_99 = NULL ;
if ( type == V_45 ) {
F_16 = V_1 -> V_30 -> V_67 ;
V_99 = V_1 -> V_30 -> V_66 ;
V_100 = V_1 -> V_30 -> V_42 ;
} else {
F_16 = ( T_8 ) V_1 -> V_30 -> V_79 ;
V_99 = V_1 -> V_30 -> V_74 ;
V_100 = V_1 -> V_30 -> V_47 ;
F_51 ( V_1 ) ;
}
if ( V_100 )
V_41 = F_56 ( V_1 , type , V_63 , V_82 , V_96 ,
V_51 , V_100 ) ;
else if ( V_99 )
V_41 = F_57 ( V_1 , V_63 , V_82 , V_96 ,
V_51 , V_99 ) ;
else
V_41 = F_58 ( V_1 , V_63 , V_82 , V_51 , F_16 ) ;
if ( type != V_45 )
F_52 ( V_1 ) ;
V_27:
if ( V_63 != V_97 )
F_65 ( V_63 ) ;
if ( ( V_41 + ( type == V_45 ) ) > 0 ) {
if ( type == V_45 )
F_38 ( V_1 ) ;
else
F_47 ( V_1 ) ;
}
return V_41 ;
}
T_2 F_66 ( struct V_1 * V_1 , const struct V_62 T_4 * V_101 ,
unsigned long V_102 , T_1 * V_51 )
{
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_69 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_6 ;
return F_63 ( V_45 , V_1 , V_101 , V_102 , V_51 ) ;
}
T_2 F_67 ( struct V_1 * V_1 , const struct V_62 T_4 * V_101 ,
unsigned long V_102 , T_1 * V_51 )
{
if ( ! ( V_1 -> V_2 & V_80 ) )
return - V_69 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_6 ;
return F_63 ( V_48 , V_1 , V_101 , V_102 , V_51 ) ;
}
static inline T_1 F_68 ( unsigned long V_103 , unsigned long V_104 )
{
#define F_69 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_103 << F_69 ) << F_69 ) | V_104 ;
}
static T_2 F_70 ( int type , struct V_1 * V_1 ,
const struct V_105 T_4 * V_89 ,
unsigned long V_82 , T_1 * V_51 )
{
T_9 V_96 ;
struct V_62 V_97 [ V_98 ] ;
struct V_62 * V_63 = V_97 ;
T_2 V_41 ;
T_8 F_16 ;
T_7 V_99 ;
T_6 V_100 ;
V_41 = F_71 ( type , V_89 , V_82 ,
V_98 , V_97 , & V_63 ) ;
if ( V_41 <= 0 )
goto V_27;
V_96 = V_41 ;
V_41 = F_27 ( type , V_1 , V_51 , V_96 ) ;
if ( V_41 < 0 )
goto V_27;
V_99 = NULL ;
if ( type == V_45 ) {
F_16 = V_1 -> V_30 -> V_67 ;
V_99 = V_1 -> V_30 -> V_66 ;
V_100 = V_1 -> V_30 -> V_42 ;
} else {
F_16 = ( T_8 ) V_1 -> V_30 -> V_79 ;
V_99 = V_1 -> V_30 -> V_74 ;
V_100 = V_1 -> V_30 -> V_47 ;
F_51 ( V_1 ) ;
}
if ( V_100 )
V_41 = F_56 ( V_1 , type , V_63 , V_82 , V_96 ,
V_51 , V_100 ) ;
else if ( V_99 )
V_41 = F_57 ( V_1 , V_63 , V_82 , V_96 ,
V_51 , V_99 ) ;
else
V_41 = F_58 ( V_1 , V_63 , V_82 , V_51 , F_16 ) ;
if ( type != V_45 )
F_52 ( V_1 ) ;
V_27:
if ( V_63 != V_97 )
F_65 ( V_63 ) ;
if ( ( V_41 + ( type == V_45 ) ) > 0 ) {
if ( type == V_45 )
F_38 ( V_1 ) ;
else
F_47 ( V_1 ) ;
}
return V_41 ;
}
static T_3 F_72 ( struct V_1 * V_1 ,
const struct V_105 T_4 * V_101 ,
unsigned long V_102 , T_1 * V_51 )
{
T_2 V_41 = - V_69 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
goto V_27;
V_41 = F_70 ( V_45 , V_1 , V_101 , V_102 , V_51 ) ;
V_27:
if ( V_41 > 0 )
F_39 ( V_73 , V_41 ) ;
F_40 ( V_73 ) ;
return V_41 ;
}
static long F_73 ( unsigned long V_32 ,
const struct V_105 T_4 * V_101 ,
unsigned long V_102 , T_1 V_51 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_51 < 0 )
return - V_6 ;
V_33 = F_74 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_69 ;
V_41 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_106 )
V_41 = F_72 ( V_33 . V_1 , V_101 , V_102 , & V_51 ) ;
F_21 ( V_33 ) ;
return V_41 ;
}
static T_3 F_75 ( struct V_1 * V_1 ,
const struct V_105 T_4 * V_101 ,
unsigned long V_102 , T_1 * V_51 )
{
T_2 V_41 = - V_69 ;
if ( ! ( V_1 -> V_2 & V_80 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
goto V_27;
V_41 = F_70 ( V_48 , V_1 , V_101 , V_102 , V_51 ) ;
V_27:
if ( V_41 > 0 )
F_48 ( V_73 , V_41 ) ;
F_49 ( V_73 ) ;
return V_41 ;
}
static long F_76 ( unsigned long V_32 ,
const struct V_105 T_4 * V_101 ,
unsigned long V_102 , T_1 V_51 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_51 < 0 )
return - V_6 ;
V_33 = F_74 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_69 ;
V_41 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_107 )
V_41 = F_75 ( V_33 . V_1 , V_101 , V_102 , & V_51 ) ;
F_21 ( V_33 ) ;
return V_41 ;
}
static T_2 F_77 ( int V_108 , int V_109 , T_1 * V_39 ,
T_3 V_50 , T_1 V_110 )
{
struct V_32 V_111 , V_27 ;
struct V_17 * V_112 , * V_113 ;
T_1 V_51 ;
T_1 V_114 ;
T_2 V_25 ;
int V_115 ;
V_25 = - V_69 ;
V_111 = F_74 ( V_109 ) ;
if ( ! V_111 . V_1 )
goto V_27;
if ( ! ( V_111 . V_1 -> V_2 & V_68 ) )
goto V_116;
V_25 = - V_24 ;
if ( ! V_39 ) {
V_51 = V_111 . V_1 -> V_7 ;
} else {
V_51 = * V_39 ;
if ( ! ( V_111 . V_1 -> V_2 & V_106 ) )
goto V_116;
}
V_25 = F_27 ( V_45 , V_111 . V_1 , & V_51 , V_50 ) ;
if ( V_25 < 0 )
goto V_116;
V_50 = V_25 ;
V_25 = - V_69 ;
V_27 = F_74 ( V_108 ) ;
if ( ! V_27 . V_1 )
goto V_116;
if ( ! ( V_27 . V_1 -> V_2 & V_80 ) )
goto V_117;
V_25 = - V_6 ;
V_112 = F_12 ( V_111 . V_1 ) ;
V_113 = F_12 ( V_27 . V_1 ) ;
V_114 = V_27 . V_1 -> V_7 ;
V_25 = F_27 ( V_48 , V_27 . V_1 , & V_114 , V_50 ) ;
if ( V_25 < 0 )
goto V_117;
V_50 = V_25 ;
if ( ! V_110 )
V_110 = F_78 ( V_112 -> V_20 -> V_21 , V_113 -> V_20 -> V_21 ) ;
if ( F_28 ( V_51 + V_50 > V_110 ) ) {
V_25 = - V_52 ;
if ( V_51 >= V_110 )
goto V_117;
V_50 = V_110 - V_51 ;
}
V_115 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_51 ( V_27 . V_1 ) ;
V_25 = F_79 ( V_111 . V_1 , & V_51 , V_27 . V_1 , & V_114 , V_50 , V_115 ) ;
F_52 ( V_27 . V_1 ) ;
if ( V_25 > 0 ) {
F_39 ( V_73 , V_25 ) ;
F_48 ( V_73 , V_25 ) ;
F_38 ( V_111 . V_1 ) ;
F_47 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_114 ;
if ( V_39 )
* V_39 = V_51 ;
else
V_111 . V_1 -> V_7 = V_51 ;
}
F_40 ( V_73 ) ;
F_49 ( V_73 ) ;
if ( V_51 > V_110 )
V_25 = - V_52 ;
V_117:
F_21 ( V_27 ) ;
V_116:
F_21 ( V_111 ) ;
V_27:
return V_25 ;
}

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
int F_22 ( int V_37 , struct V_1 * V_1 , const T_1 * V_38 , T_2 V_39 )
{
struct V_17 * V_17 ;
T_1 V_40 ;
int V_25 = - V_6 ;
V_17 = F_12 ( V_1 ) ;
if ( F_23 ( ( V_41 ) V_39 < 0 ) )
return V_25 ;
V_40 = * V_38 ;
if ( F_23 ( V_40 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_39 >= - V_40 )
return - V_42 ;
} else if ( F_23 ( ( T_1 ) ( V_40 + V_39 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_23 ( V_17 -> V_43 && F_24 ( V_17 ) ) ) {
V_25 = F_25 (
V_37 == V_44 ? V_45 : V_46 ,
V_17 , V_1 , V_40 , V_39 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_26 ( V_1 ,
V_37 == V_44 ? V_47 : V_48 ) ;
if ( V_25 )
return V_25 ;
return V_39 > V_49 ? V_49 : V_39 ;
}
V_41 F_27 ( struct V_1 * V_50 , char T_3 * V_51 , T_2 V_52 , T_1 * V_38 )
{
struct V_53 V_54 = { . V_55 = V_51 , . V_56 = V_52 } ;
struct V_57 V_57 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
V_58 = V_50 -> V_30 -> V_61 ( & V_57 , & V_54 , 1 , V_57 . V_59 ) ;
if ( - V_62 == V_58 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
V_41 F_30 ( struct V_1 * V_50 , char T_3 * V_51 , T_2 V_52 , T_1 * V_38 )
{
struct V_53 V_54 = { . V_55 = V_51 , . V_56 = V_52 } ;
struct V_57 V_57 ;
struct V_63 V_64 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
F_31 ( & V_64 , V_44 , & V_54 , 1 , V_52 ) ;
V_58 = V_50 -> V_30 -> V_65 ( & V_57 , & V_64 ) ;
if ( - V_62 == V_58 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
V_41 F_32 ( struct V_1 * V_1 , char T_3 * V_51 , T_2 V_39 ,
T_1 * V_40 )
{
V_41 V_58 ;
if ( V_1 -> V_30 -> V_66 )
V_58 = V_1 -> V_30 -> V_66 ( V_1 , V_51 , V_39 , V_40 ) ;
else if ( V_1 -> V_30 -> V_61 )
V_58 = F_27 ( V_1 , V_51 , V_39 , V_40 ) ;
else if ( V_1 -> V_30 -> V_65 )
V_58 = F_30 ( V_1 , V_51 , V_39 , V_40 ) ;
else
V_58 = - V_6 ;
return V_58 ;
}
V_41 F_33 ( struct V_1 * V_1 , char T_3 * V_51 , T_2 V_39 , T_1 * V_40 )
{
V_41 V_58 ;
if ( ! ( V_1 -> V_2 & V_67 ) )
return - V_68 ;
if ( ! ( V_1 -> V_2 & V_69 ) )
return - V_6 ;
if ( F_23 ( ! F_34 ( V_70 , V_51 , V_39 ) ) )
return - V_71 ;
V_58 = F_22 ( V_44 , V_1 , V_40 , V_39 ) ;
if ( V_58 >= 0 ) {
V_39 = V_58 ;
V_58 = F_32 ( V_1 , V_51 , V_39 , V_40 ) ;
if ( V_58 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_72 , V_58 ) ;
}
F_37 ( V_72 ) ;
}
return V_58 ;
}
V_41 F_38 ( struct V_1 * V_50 , const char T_3 * V_51 , T_2 V_52 , T_1 * V_38 )
{
struct V_53 V_54 = { . V_55 = ( void T_3 * ) V_51 , . V_56 = V_52 } ;
struct V_57 V_57 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
V_58 = V_50 -> V_30 -> V_73 ( & V_57 , & V_54 , 1 , V_57 . V_59 ) ;
if ( - V_62 == V_58 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
V_41 F_39 ( struct V_1 * V_50 , const char T_3 * V_51 , T_2 V_52 , T_1 * V_38 )
{
struct V_53 V_54 = { . V_55 = ( void T_3 * ) V_51 , . V_56 = V_52 } ;
struct V_57 V_57 ;
struct V_63 V_64 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
F_31 ( & V_64 , V_74 , & V_54 , 1 , V_52 ) ;
V_58 = V_50 -> V_30 -> V_75 ( & V_57 , & V_64 ) ;
if ( - V_62 == V_58 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
V_41 F_40 ( struct V_1 * V_1 , const char * V_51 , T_2 V_39 , T_1 * V_40 )
{
T_4 V_76 ;
const char T_3 * V_77 ;
V_41 V_58 ;
if ( ! ( V_1 -> V_2 & V_78 ) )
return - V_6 ;
V_76 = F_41 () ;
F_42 ( F_43 () ) ;
V_77 = ( V_79 const char T_3 * ) V_51 ;
if ( V_39 > V_49 )
V_39 = V_49 ;
if ( V_1 -> V_30 -> V_80 )
V_58 = V_1 -> V_30 -> V_80 ( V_1 , V_77 , V_39 , V_40 ) ;
else if ( V_1 -> V_30 -> V_73 )
V_58 = F_38 ( V_1 , V_77 , V_39 , V_40 ) ;
else
V_58 = F_39 ( V_1 , V_77 , V_39 , V_40 ) ;
F_42 ( V_76 ) ;
if ( V_58 > 0 ) {
F_44 ( V_1 ) ;
F_45 ( V_72 , V_58 ) ;
}
F_46 ( V_72 ) ;
return V_58 ;
}
V_41 F_47 ( struct V_1 * V_1 , const char T_3 * V_51 , T_2 V_39 , T_1 * V_40 )
{
V_41 V_58 ;
if ( ! ( V_1 -> V_2 & V_81 ) )
return - V_68 ;
if ( ! ( V_1 -> V_2 & V_78 ) )
return - V_6 ;
if ( F_23 ( ! F_34 ( V_82 , V_51 , V_39 ) ) )
return - V_71 ;
V_58 = F_22 ( V_74 , V_1 , V_40 , V_39 ) ;
if ( V_58 >= 0 ) {
V_39 = V_58 ;
F_48 ( V_1 ) ;
if ( V_1 -> V_30 -> V_80 )
V_58 = V_1 -> V_30 -> V_80 ( V_1 , V_51 , V_39 , V_40 ) ;
else if ( V_1 -> V_30 -> V_73 )
V_58 = F_38 ( V_1 , V_51 , V_39 , V_40 ) ;
else
V_58 = F_39 ( V_1 , V_51 , V_39 , V_40 ) ;
if ( V_58 > 0 ) {
F_44 ( V_1 ) ;
F_45 ( V_72 , V_58 ) ;
}
F_46 ( V_72 ) ;
F_49 ( V_1 ) ;
}
return V_58 ;
}
static inline T_1 F_50 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_51 ( struct V_1 * V_1 , T_1 V_40 )
{
V_1 -> V_7 = V_40 ;
}
unsigned long F_52 ( struct V_53 * V_54 , unsigned long V_83 , T_2 V_84 )
{
unsigned long V_85 = 0 ;
T_2 V_52 = 0 ;
while ( V_85 < V_83 ) {
V_85 ++ ;
if ( V_52 + V_54 -> V_56 >= V_84 ) {
V_54 -> V_56 = V_84 - V_52 ;
break;
}
V_52 += V_54 -> V_56 ;
V_54 ++ ;
}
return V_85 ;
}
static V_41 F_53 ( struct V_1 * V_50 , int V_86 , const struct V_53 * V_54 ,
unsigned long V_83 , T_2 V_52 , T_1 * V_38 , T_5 F_16 )
{
struct V_57 V_57 ;
struct V_63 V_64 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
F_31 ( & V_64 , V_86 , V_54 , V_83 , V_52 ) ;
V_58 = F_16 ( & V_57 , & V_64 ) ;
if ( V_58 == - V_62 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
static V_41 F_54 ( struct V_1 * V_50 , const struct V_53 * V_54 ,
unsigned long V_83 , T_2 V_52 , T_1 * V_38 , T_6 F_16 )
{
struct V_57 V_57 ;
V_41 V_58 ;
F_28 ( & V_57 , V_50 ) ;
V_57 . V_59 = * V_38 ;
V_57 . V_60 = V_52 ;
V_58 = F_16 ( & V_57 , V_54 , V_83 , V_57 . V_59 ) ;
if ( V_58 == - V_62 )
V_58 = F_29 ( & V_57 ) ;
* V_38 = V_57 . V_59 ;
return V_58 ;
}
static V_41 F_55 ( struct V_1 * V_50 , struct V_53 * V_54 ,
unsigned long V_83 , T_1 * V_38 , T_7 F_16 )
{
struct V_53 * V_87 = V_54 ;
V_41 V_58 = 0 ;
while ( V_83 > 0 ) {
void T_3 * V_88 ;
T_2 V_52 ;
V_41 V_89 ;
V_88 = V_87 -> V_55 ;
V_52 = V_87 -> V_56 ;
V_87 ++ ;
V_83 -- ;
V_89 = F_16 ( V_50 , V_88 , V_52 , V_38 ) ;
if ( V_89 < 0 ) {
if ( ! V_58 )
V_58 = V_89 ;
break;
}
V_58 += V_89 ;
if ( V_89 != V_52 )
break;
}
return V_58 ;
}
V_41 F_56 ( int type , const struct V_53 T_3 * V_90 ,
unsigned long V_83 , unsigned long V_91 ,
struct V_53 * V_92 ,
struct V_53 * * V_93 )
{
unsigned long V_85 ;
V_41 V_58 ;
struct V_53 * V_54 = V_92 ;
if ( V_83 == 0 ) {
V_58 = 0 ;
goto V_27;
}
if ( V_83 > V_94 ) {
V_58 = - V_6 ;
goto V_27;
}
if ( V_83 > V_91 ) {
V_54 = F_57 ( V_83 * sizeof( struct V_53 ) , V_95 ) ;
if ( V_54 == NULL ) {
V_58 = - V_96 ;
goto V_27;
}
}
if ( F_58 ( V_54 , V_90 , V_83 * sizeof( * V_90 ) ) ) {
V_58 = - V_71 ;
goto V_27;
}
V_58 = 0 ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ ) {
void T_3 * V_51 = V_54 [ V_85 ] . V_55 ;
V_41 V_52 = ( V_41 ) V_54 [ V_85 ] . V_56 ;
if ( V_52 < 0 ) {
V_58 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_23 ( ! F_34 ( F_59 ( type ) , V_51 , V_52 ) ) ) {
V_58 = - V_71 ;
goto V_27;
}
if ( V_52 > V_49 - V_58 ) {
V_52 = V_49 - V_58 ;
V_54 [ V_85 ] . V_56 = V_52 ;
}
V_58 += V_52 ;
}
V_27:
* V_93 = V_54 ;
return V_58 ;
}
static V_41 F_60 ( int type , struct V_1 * V_1 ,
const struct V_53 T_3 * V_90 ,
unsigned long V_83 , T_1 * V_40 )
{
T_2 V_97 ;
struct V_53 V_98 [ V_99 ] ;
struct V_53 * V_54 = V_98 ;
V_41 V_58 ;
T_7 F_16 ;
T_6 V_100 ;
T_5 V_101 ;
V_58 = F_56 ( type , V_90 , V_83 ,
F_61 ( V_98 ) , V_98 , & V_54 ) ;
if ( V_58 <= 0 )
goto V_27;
V_97 = V_58 ;
V_58 = F_22 ( type , V_1 , V_40 , V_97 ) ;
if ( V_58 < 0 )
goto V_27;
V_100 = NULL ;
if ( type == V_44 ) {
F_16 = V_1 -> V_30 -> V_66 ;
V_100 = V_1 -> V_30 -> V_61 ;
V_101 = V_1 -> V_30 -> V_65 ;
} else {
F_16 = ( T_7 ) V_1 -> V_30 -> V_80 ;
V_100 = V_1 -> V_30 -> V_73 ;
V_101 = V_1 -> V_30 -> V_75 ;
F_48 ( V_1 ) ;
}
if ( V_101 )
V_58 = F_53 ( V_1 , type , V_54 , V_83 , V_97 ,
V_40 , V_101 ) ;
else if ( V_100 )
V_58 = F_54 ( V_1 , V_54 , V_83 , V_97 ,
V_40 , V_100 ) ;
else
V_58 = F_55 ( V_1 , V_54 , V_83 , V_40 , F_16 ) ;
if ( type != V_44 )
F_49 ( V_1 ) ;
V_27:
if ( V_54 != V_98 )
F_62 ( V_54 ) ;
if ( ( V_58 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_35 ( V_1 ) ;
else
F_44 ( V_1 ) ;
}
return V_58 ;
}
V_41 F_63 ( struct V_1 * V_1 , const struct V_53 T_3 * V_102 ,
unsigned long V_103 , T_1 * V_40 )
{
if ( ! ( V_1 -> V_2 & V_67 ) )
return - V_68 ;
if ( ! ( V_1 -> V_2 & V_69 ) )
return - V_6 ;
return F_60 ( V_44 , V_1 , V_102 , V_103 , V_40 ) ;
}
V_41 F_64 ( struct V_1 * V_1 , const struct V_53 T_3 * V_102 ,
unsigned long V_103 , T_1 * V_40 )
{
if ( ! ( V_1 -> V_2 & V_81 ) )
return - V_68 ;
if ( ! ( V_1 -> V_2 & V_78 ) )
return - V_6 ;
return F_60 ( V_74 , V_1 , V_102 , V_103 , V_40 ) ;
}
static inline T_1 F_65 ( unsigned long V_104 , unsigned long V_105 )
{
#define F_66 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_104 << F_66 ) << F_66 ) | V_105 ;
}
static V_41 F_67 ( int type , struct V_1 * V_1 ,
const struct V_106 T_3 * V_90 ,
unsigned long V_83 , T_1 * V_40 )
{
T_8 V_97 ;
struct V_53 V_98 [ V_99 ] ;
struct V_53 * V_54 = V_98 ;
V_41 V_58 ;
T_7 F_16 ;
T_6 V_100 ;
T_5 V_101 ;
V_58 = F_68 ( type , V_90 , V_83 ,
V_99 , V_98 , & V_54 ) ;
if ( V_58 <= 0 )
goto V_27;
V_97 = V_58 ;
V_58 = F_22 ( type , V_1 , V_40 , V_97 ) ;
if ( V_58 < 0 )
goto V_27;
V_100 = NULL ;
if ( type == V_44 ) {
F_16 = V_1 -> V_30 -> V_66 ;
V_100 = V_1 -> V_30 -> V_61 ;
V_101 = V_1 -> V_30 -> V_65 ;
} else {
F_16 = ( T_7 ) V_1 -> V_30 -> V_80 ;
V_100 = V_1 -> V_30 -> V_73 ;
V_101 = V_1 -> V_30 -> V_75 ;
F_48 ( V_1 ) ;
}
if ( V_101 )
V_58 = F_53 ( V_1 , type , V_54 , V_83 , V_97 ,
V_40 , V_101 ) ;
else if ( V_100 )
V_58 = F_54 ( V_1 , V_54 , V_83 , V_97 ,
V_40 , V_100 ) ;
else
V_58 = F_55 ( V_1 , V_54 , V_83 , V_40 , F_16 ) ;
if ( type != V_44 )
F_49 ( V_1 ) ;
V_27:
if ( V_54 != V_98 )
F_62 ( V_54 ) ;
if ( ( V_58 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_35 ( V_1 ) ;
else
F_44 ( V_1 ) ;
}
return V_58 ;
}
static T_2 F_69 ( struct V_1 * V_1 ,
const struct V_106 T_3 * V_102 ,
unsigned long V_103 , T_1 * V_40 )
{
V_41 V_58 = - V_68 ;
if ( ! ( V_1 -> V_2 & V_67 ) )
goto V_27;
V_58 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_69 ) )
goto V_27;
V_58 = F_67 ( V_44 , V_1 , V_102 , V_103 , V_40 ) ;
V_27:
if ( V_58 > 0 )
F_36 ( V_72 , V_58 ) ;
F_37 ( V_72 ) ;
return V_58 ;
}
static long F_70 ( unsigned long V_32 ,
const struct V_106 T_3 * V_102 ,
unsigned long V_103 , T_1 V_40 )
{
struct V_32 V_33 ;
V_41 V_58 ;
if ( V_40 < 0 )
return - V_6 ;
V_33 = F_71 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_68 ;
V_58 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_107 )
V_58 = F_69 ( V_33 . V_1 , V_102 , V_103 , & V_40 ) ;
F_21 ( V_33 ) ;
return V_58 ;
}
static T_2 F_72 ( struct V_1 * V_1 ,
const struct V_106 T_3 * V_102 ,
unsigned long V_103 , T_1 * V_40 )
{
V_41 V_58 = - V_68 ;
if ( ! ( V_1 -> V_2 & V_81 ) )
goto V_27;
V_58 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_78 ) )
goto V_27;
V_58 = F_67 ( V_74 , V_1 , V_102 , V_103 , V_40 ) ;
V_27:
if ( V_58 > 0 )
F_45 ( V_72 , V_58 ) ;
F_46 ( V_72 ) ;
return V_58 ;
}
static long F_73 ( unsigned long V_32 ,
const struct V_106 T_3 * V_102 ,
unsigned long V_103 , T_1 V_40 )
{
struct V_32 V_33 ;
V_41 V_58 ;
if ( V_40 < 0 )
return - V_6 ;
V_33 = F_71 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_68 ;
V_58 = - V_24 ;
if ( V_33 . V_1 -> V_2 & V_108 )
V_58 = F_72 ( V_33 . V_1 , V_102 , V_103 , & V_40 ) ;
F_21 ( V_33 ) ;
return V_58 ;
}
static V_41 F_74 ( int V_109 , int V_110 , T_1 * V_38 ,
T_2 V_39 , T_1 V_111 )
{
struct V_32 V_112 , V_27 ;
struct V_17 * V_113 , * V_114 ;
T_1 V_40 ;
T_1 V_115 ;
V_41 V_25 ;
int V_116 ;
V_25 = - V_68 ;
V_112 = F_71 ( V_110 ) ;
if ( ! V_112 . V_1 )
goto V_27;
if ( ! ( V_112 . V_1 -> V_2 & V_67 ) )
goto V_117;
V_25 = - V_24 ;
if ( ! V_38 ) {
V_40 = V_112 . V_1 -> V_7 ;
} else {
V_40 = * V_38 ;
if ( ! ( V_112 . V_1 -> V_2 & V_107 ) )
goto V_117;
}
V_25 = F_22 ( V_44 , V_112 . V_1 , & V_40 , V_39 ) ;
if ( V_25 < 0 )
goto V_117;
V_39 = V_25 ;
V_25 = - V_68 ;
V_27 = F_71 ( V_109 ) ;
if ( ! V_27 . V_1 )
goto V_117;
if ( ! ( V_27 . V_1 -> V_2 & V_81 ) )
goto V_118;
V_25 = - V_6 ;
V_113 = F_12 ( V_112 . V_1 ) ;
V_114 = F_12 ( V_27 . V_1 ) ;
V_115 = V_27 . V_1 -> V_7 ;
V_25 = F_22 ( V_74 , V_27 . V_1 , & V_115 , V_39 ) ;
if ( V_25 < 0 )
goto V_118;
V_39 = V_25 ;
if ( ! V_111 )
V_111 = F_75 ( V_113 -> V_20 -> V_21 , V_114 -> V_20 -> V_21 ) ;
if ( F_23 ( V_40 + V_39 > V_111 ) ) {
V_25 = - V_42 ;
if ( V_40 >= V_111 )
goto V_118;
V_39 = V_111 - V_40 ;
}
V_116 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_48 ( V_27 . V_1 ) ;
V_25 = F_76 ( V_112 . V_1 , & V_40 , V_27 . V_1 , & V_115 , V_39 , V_116 ) ;
F_49 ( V_27 . V_1 ) ;
if ( V_25 > 0 ) {
F_36 ( V_72 , V_25 ) ;
F_45 ( V_72 , V_25 ) ;
F_35 ( V_112 . V_1 ) ;
F_44 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_115 ;
if ( V_38 )
* V_38 = V_40 ;
else
V_112 . V_1 -> V_7 = V_40 ;
}
F_37 ( V_72 ) ;
F_46 ( V_72 ) ;
if ( V_40 > V_111 )
V_25 = - V_42 ;
V_118:
F_21 ( V_27 ) ;
V_117:
F_21 ( V_112 ) ;
V_27:
return V_25 ;
}

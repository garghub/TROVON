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
if ( V_1 -> V_30 && V_1 -> V_30 -> V_31 )
F_16 = V_1 -> V_30 -> V_31 ;
}
return F_16 ( V_1 , V_4 , V_9 ) ;
}
int F_17 ( int V_32 , struct V_1 * V_1 , const T_1 * V_33 , T_2 V_34 )
{
struct V_17 * V_17 ;
T_1 V_35 ;
int V_25 = - V_6 ;
V_17 = F_12 ( V_1 ) ;
if ( F_18 ( ( V_36 ) V_34 < 0 ) )
return V_25 ;
V_35 = * V_33 ;
if ( F_18 ( V_35 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_34 >= - V_35 )
return - V_37 ;
} else if ( F_18 ( ( T_1 ) ( V_35 + V_34 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_18 ( V_17 -> V_38 && F_19 ( V_17 ) ) ) {
V_25 = F_20 (
V_32 == V_39 ? V_40 : V_41 ,
V_17 , V_1 , V_35 , V_34 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_21 ( V_1 ,
V_32 == V_39 ? V_42 : V_43 ) ;
if ( V_25 )
return V_25 ;
return V_34 > V_44 ? V_44 : V_34 ;
}
V_36 F_22 ( struct V_1 * V_45 , char T_3 * V_46 , T_2 V_47 , T_1 * V_33 )
{
struct V_48 V_49 = { . V_50 = V_46 , . V_51 = V_47 } ;
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_52 . V_56 = V_47 ;
V_53 = V_45 -> V_30 -> V_57 ( & V_52 , & V_49 , 1 , V_52 . V_54 ) ;
if ( - V_58 == V_53 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
V_36 F_25 ( struct V_1 * V_1 , char T_3 * V_46 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_53 ;
if ( ! ( V_1 -> V_2 & V_59 ) )
return - V_60 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_61 && ! V_1 -> V_30 -> V_57 ) )
return - V_6 ;
if ( F_18 ( ! F_26 ( V_62 , V_46 , V_34 ) ) )
return - V_63 ;
V_53 = F_17 ( V_39 , V_1 , V_35 , V_34 ) ;
if ( V_53 >= 0 ) {
V_34 = V_53 ;
if ( V_1 -> V_30 -> V_61 )
V_53 = V_1 -> V_30 -> V_61 ( V_1 , V_46 , V_34 , V_35 ) ;
else
V_53 = F_22 ( V_1 , V_46 , V_34 , V_35 ) ;
if ( V_53 > 0 ) {
F_27 ( V_1 ) ;
F_28 ( V_64 , V_53 ) ;
}
F_29 ( V_64 ) ;
}
return V_53 ;
}
V_36 F_30 ( struct V_1 * V_45 , const char T_3 * V_46 , T_2 V_47 , T_1 * V_33 )
{
struct V_48 V_49 = { . V_50 = ( void T_3 * ) V_46 , . V_51 = V_47 } ;
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_52 . V_56 = V_47 ;
V_53 = V_45 -> V_30 -> V_65 ( & V_52 , & V_49 , 1 , V_52 . V_54 ) ;
if ( - V_58 == V_53 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
V_36 F_31 ( struct V_1 * V_1 , const char * V_46 , T_2 V_34 , T_1 * V_35 )
{
T_4 V_66 ;
const char T_3 * V_67 ;
V_36 V_53 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_68 && ! V_1 -> V_30 -> V_65 ) )
return - V_6 ;
V_66 = F_32 () ;
F_33 ( F_34 () ) ;
V_67 = ( V_69 const char T_3 * ) V_46 ;
if ( V_34 > V_44 )
V_34 = V_44 ;
if ( V_1 -> V_30 -> V_68 )
V_53 = V_1 -> V_30 -> V_68 ( V_1 , V_67 , V_34 , V_35 ) ;
else
V_53 = F_30 ( V_1 , V_67 , V_34 , V_35 ) ;
F_33 ( V_66 ) ;
if ( V_53 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_64 , V_53 ) ;
}
F_37 ( V_64 ) ;
return V_53 ;
}
V_36 F_38 ( struct V_1 * V_1 , const char T_3 * V_46 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_53 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_60 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_68 && ! V_1 -> V_30 -> V_65 ) )
return - V_6 ;
if ( F_18 ( ! F_26 ( V_71 , V_46 , V_34 ) ) )
return - V_63 ;
V_53 = F_17 ( V_72 , V_1 , V_35 , V_34 ) ;
if ( V_53 >= 0 ) {
V_34 = V_53 ;
F_39 ( V_1 ) ;
if ( V_1 -> V_30 -> V_68 )
V_53 = V_1 -> V_30 -> V_68 ( V_1 , V_46 , V_34 , V_35 ) ;
else
V_53 = F_30 ( V_1 , V_46 , V_34 , V_35 ) ;
if ( V_53 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_64 , V_53 ) ;
}
F_37 ( V_64 ) ;
F_40 ( V_1 ) ;
}
return V_53 ;
}
static inline T_1 F_41 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_42 ( struct V_1 * V_1 , T_1 V_35 )
{
V_1 -> V_7 = V_35 ;
}
unsigned long F_43 ( struct V_48 * V_49 , unsigned long V_73 , T_2 V_74 )
{
unsigned long V_75 = 0 ;
T_2 V_47 = 0 ;
while ( V_75 < V_73 ) {
V_75 ++ ;
if ( V_47 + V_49 -> V_51 >= V_74 ) {
V_49 -> V_51 = V_74 - V_47 ;
break;
}
V_47 += V_49 -> V_51 ;
V_49 ++ ;
}
return V_75 ;
}
static V_36 F_44 ( struct V_1 * V_45 , const struct V_48 * V_49 ,
unsigned long V_73 , T_2 V_47 , T_1 * V_33 , T_5 F_16 )
{
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_52 . V_56 = V_47 ;
V_53 = F_16 ( & V_52 , V_49 , V_73 , V_52 . V_54 ) ;
if ( V_53 == - V_58 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
static V_36 F_45 ( struct V_1 * V_45 , struct V_48 * V_49 ,
unsigned long V_73 , T_1 * V_33 , T_6 F_16 )
{
struct V_48 * V_76 = V_49 ;
V_36 V_53 = 0 ;
while ( V_73 > 0 ) {
void T_3 * V_77 ;
T_2 V_47 ;
V_36 V_78 ;
V_77 = V_76 -> V_50 ;
V_47 = V_76 -> V_51 ;
V_76 ++ ;
V_73 -- ;
V_78 = F_16 ( V_45 , V_77 , V_47 , V_33 ) ;
if ( V_78 < 0 ) {
if ( ! V_53 )
V_53 = V_78 ;
break;
}
V_53 += V_78 ;
if ( V_78 != V_47 )
break;
}
return V_53 ;
}
V_36 F_46 ( int type , const struct V_48 T_3 * V_79 ,
unsigned long V_73 , unsigned long V_80 ,
struct V_48 * V_81 ,
struct V_48 * * V_82 )
{
unsigned long V_75 ;
V_36 V_53 ;
struct V_48 * V_49 = V_81 ;
if ( V_73 == 0 ) {
V_53 = 0 ;
goto V_27;
}
if ( V_73 > V_83 ) {
V_53 = - V_6 ;
goto V_27;
}
if ( V_73 > V_80 ) {
V_49 = F_47 ( V_73 * sizeof( struct V_48 ) , V_84 ) ;
if ( V_49 == NULL ) {
V_53 = - V_85 ;
goto V_27;
}
}
if ( F_48 ( V_49 , V_79 , V_73 * sizeof( * V_79 ) ) ) {
V_53 = - V_63 ;
goto V_27;
}
V_53 = 0 ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ ) {
void T_3 * V_46 = V_49 [ V_75 ] . V_50 ;
V_36 V_47 = ( V_36 ) V_49 [ V_75 ] . V_51 ;
if ( V_47 < 0 ) {
V_53 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_18 ( ! F_26 ( F_49 ( type ) , V_46 , V_47 ) ) ) {
V_53 = - V_63 ;
goto V_27;
}
if ( V_47 > V_44 - V_53 ) {
V_47 = V_44 - V_53 ;
V_49 [ V_75 ] . V_51 = V_47 ;
}
V_53 += V_47 ;
}
V_27:
* V_82 = V_49 ;
return V_53 ;
}
static V_36 F_50 ( int type , struct V_1 * V_1 ,
const struct V_48 T_3 * V_79 ,
unsigned long V_73 , T_1 * V_35 )
{
T_2 V_86 ;
struct V_48 V_87 [ V_88 ] ;
struct V_48 * V_49 = V_87 ;
V_36 V_53 ;
T_6 F_16 ;
T_5 V_89 ;
if ( ! V_1 -> V_30 ) {
V_53 = - V_6 ;
goto V_27;
}
V_53 = F_46 ( type , V_79 , V_73 ,
F_51 ( V_87 ) , V_87 , & V_49 ) ;
if ( V_53 <= 0 )
goto V_27;
V_86 = V_53 ;
V_53 = F_17 ( type , V_1 , V_35 , V_86 ) ;
if ( V_53 < 0 )
goto V_27;
V_89 = NULL ;
if ( type == V_39 ) {
F_16 = V_1 -> V_30 -> V_61 ;
V_89 = V_1 -> V_30 -> V_57 ;
} else {
F_16 = ( T_6 ) V_1 -> V_30 -> V_68 ;
V_89 = V_1 -> V_30 -> V_65 ;
F_39 ( V_1 ) ;
}
if ( V_89 )
V_53 = F_44 ( V_1 , V_49 , V_73 , V_86 ,
V_35 , V_89 ) ;
else
V_53 = F_45 ( V_1 , V_49 , V_73 , V_35 , F_16 ) ;
if ( type != V_39 )
F_40 ( V_1 ) ;
V_27:
if ( V_49 != V_87 )
F_52 ( V_49 ) ;
if ( ( V_53 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_27 ( V_1 ) ;
else
F_35 ( V_1 ) ;
}
return V_53 ;
}
V_36 F_53 ( struct V_1 * V_1 , const struct V_48 T_3 * V_90 ,
unsigned long V_91 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_59 ) )
return - V_60 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_57 && ! V_1 -> V_30 -> V_61 ) )
return - V_6 ;
return F_50 ( V_39 , V_1 , V_90 , V_91 , V_35 ) ;
}
V_36 F_54 ( struct V_1 * V_1 , const struct V_48 T_3 * V_90 ,
unsigned long V_91 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_60 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_65 && ! V_1 -> V_30 -> V_68 ) )
return - V_6 ;
return F_50 ( V_72 , V_1 , V_90 , V_91 , V_35 ) ;
}
static inline T_1 F_55 ( unsigned long V_92 , unsigned long V_93 )
{
#define F_56 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_92 << F_56 ) << F_56 ) | V_93 ;
}
static V_36 F_57 ( int type , struct V_1 * V_1 ,
const struct V_94 T_3 * V_79 ,
unsigned long V_73 , T_1 * V_35 )
{
T_7 V_86 ;
struct V_48 V_87 [ V_88 ] ;
struct V_48 * V_49 = V_87 ;
V_36 V_53 ;
T_6 F_16 ;
T_5 V_89 ;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 )
goto V_27;
V_53 = - V_63 ;
if ( ! F_26 ( V_71 , V_79 , V_73 * sizeof( * V_79 ) ) )
goto V_27;
V_53 = F_58 ( type , V_79 , V_73 ,
V_88 , V_87 , & V_49 ) ;
if ( V_53 <= 0 )
goto V_27;
V_86 = V_53 ;
V_53 = F_17 ( type , V_1 , V_35 , V_86 ) ;
if ( V_53 < 0 )
goto V_27;
V_89 = NULL ;
if ( type == V_39 ) {
F_16 = V_1 -> V_30 -> V_61 ;
V_89 = V_1 -> V_30 -> V_57 ;
} else {
F_16 = ( T_6 ) V_1 -> V_30 -> V_68 ;
V_89 = V_1 -> V_30 -> V_65 ;
F_39 ( V_1 ) ;
}
if ( V_89 )
V_53 = F_44 ( V_1 , V_49 , V_73 , V_86 ,
V_35 , V_89 ) ;
else
V_53 = F_45 ( V_1 , V_49 , V_73 , V_35 , F_16 ) ;
if ( type != V_39 )
F_40 ( V_1 ) ;
V_27:
if ( V_49 != V_87 )
F_52 ( V_49 ) ;
if ( ( V_53 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_27 ( V_1 ) ;
else
F_35 ( V_1 ) ;
}
return V_53 ;
}
static T_2 F_59 ( struct V_1 * V_1 ,
const struct V_94 T_3 * V_90 ,
unsigned long V_91 , T_1 * V_35 )
{
V_36 V_53 = - V_60 ;
if ( ! ( V_1 -> V_2 & V_59 ) )
goto V_27;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_57 && ! V_1 -> V_30 -> V_61 ) )
goto V_27;
V_53 = F_57 ( V_39 , V_1 , V_90 , V_91 , V_35 ) ;
V_27:
if ( V_53 > 0 )
F_28 ( V_64 , V_53 ) ;
F_29 ( V_64 ) ;
return V_53 ;
}
static T_2 F_60 ( struct V_1 * V_1 ,
const struct V_94 T_3 * V_90 ,
unsigned long V_91 , T_1 * V_35 )
{
V_36 V_53 = - V_60 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
goto V_27;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_65 && ! V_1 -> V_30 -> V_68 ) )
goto V_27;
V_53 = F_57 ( V_72 , V_1 , V_90 , V_91 , V_35 ) ;
V_27:
if ( V_53 > 0 )
F_36 ( V_64 , V_53 ) ;
F_37 ( V_64 ) ;
return V_53 ;
}
static V_36 F_61 ( int V_95 , int V_96 , T_1 * V_33 ,
T_2 V_34 , T_1 V_97 )
{
struct V_98 V_99 , V_27 ;
struct V_17 * V_100 , * V_101 ;
T_1 V_35 ;
T_1 V_102 ;
V_36 V_25 ;
int V_103 ;
V_25 = - V_60 ;
V_99 = F_62 ( V_96 ) ;
if ( ! V_99 . V_1 )
goto V_27;
if ( ! ( V_99 . V_1 -> V_2 & V_59 ) )
goto V_104;
V_25 = - V_24 ;
if ( ! V_33 ) {
V_35 = V_99 . V_1 -> V_7 ;
} else {
V_35 = * V_33 ;
if ( ! ( V_99 . V_1 -> V_2 & V_105 ) )
goto V_104;
}
V_25 = F_17 ( V_39 , V_99 . V_1 , & V_35 , V_34 ) ;
if ( V_25 < 0 )
goto V_104;
V_34 = V_25 ;
V_25 = - V_60 ;
V_27 = F_62 ( V_95 ) ;
if ( ! V_27 . V_1 )
goto V_104;
if ( ! ( V_27 . V_1 -> V_2 & V_70 ) )
goto V_106;
V_25 = - V_6 ;
V_100 = F_12 ( V_99 . V_1 ) ;
V_101 = F_12 ( V_27 . V_1 ) ;
V_102 = V_27 . V_1 -> V_7 ;
V_25 = F_17 ( V_72 , V_27 . V_1 , & V_102 , V_34 ) ;
if ( V_25 < 0 )
goto V_106;
V_34 = V_25 ;
if ( ! V_97 )
V_97 = F_63 ( V_100 -> V_20 -> V_21 , V_101 -> V_20 -> V_21 ) ;
if ( F_18 ( V_35 + V_34 > V_97 ) ) {
V_25 = - V_37 ;
if ( V_35 >= V_97 )
goto V_106;
V_34 = V_97 - V_35 ;
}
V_103 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_39 ( V_27 . V_1 ) ;
V_25 = F_64 ( V_99 . V_1 , & V_35 , V_27 . V_1 , & V_102 , V_34 , V_103 ) ;
F_40 ( V_27 . V_1 ) ;
if ( V_25 > 0 ) {
F_28 ( V_64 , V_25 ) ;
F_36 ( V_64 , V_25 ) ;
F_27 ( V_99 . V_1 ) ;
F_35 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_102 ;
if ( V_33 )
* V_33 = V_35 ;
else
V_99 . V_1 -> V_7 = V_35 ;
}
F_29 ( V_64 ) ;
F_37 ( V_64 ) ;
if ( V_35 > V_97 )
V_25 = - V_37 ;
V_106:
F_65 ( V_27 ) ;
V_104:
F_65 ( V_99 ) ;
V_27:
return V_25 ;
}

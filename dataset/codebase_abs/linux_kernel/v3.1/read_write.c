static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
T_1
F_2 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
struct V_6 * V_6 = V_1 -> V_7 -> V_8 ;
switch ( V_5 ) {
case V_9 :
V_4 += V_6 -> V_10 ;
break;
case V_11 :
if ( V_4 == 0 )
return V_1 -> V_12 ;
V_4 += V_1 -> V_12 ;
break;
case V_13 :
if ( V_4 >= V_6 -> V_10 )
return - V_14 ;
break;
case V_15 :
if ( V_4 >= V_6 -> V_10 )
return - V_14 ;
V_4 = V_6 -> V_10 ;
break;
}
if ( V_4 < 0 && ! F_1 ( V_1 ) )
return - V_16 ;
if ( V_4 > V_6 -> V_17 -> V_18 )
return - V_16 ;
if ( V_4 != V_1 -> V_12 ) {
V_1 -> V_12 = V_4 ;
V_1 -> V_19 = 0 ;
}
return V_4 ;
}
T_1 F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
T_1 V_20 ;
F_4 ( & V_1 -> V_21 -> V_22 -> V_23 ) ;
V_20 = F_2 ( V_1 , V_4 , V_5 ) ;
F_5 ( & V_1 -> V_21 -> V_22 -> V_23 ) ;
return V_20 ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
return V_1 -> V_12 ;
}
T_1 F_7 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
return - V_24 ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
struct V_6 * V_6 = V_1 -> V_25 . V_26 -> V_22 ;
T_1 V_27 ;
F_4 ( & V_6 -> V_23 ) ;
switch ( V_5 ) {
case V_9 :
V_4 += F_9 ( V_6 ) ;
break;
case V_11 :
if ( V_4 == 0 ) {
V_27 = V_1 -> V_12 ;
goto V_28;
}
V_4 += V_1 -> V_12 ;
break;
case V_13 :
if ( V_4 >= V_6 -> V_10 ) {
V_27 = - V_14 ;
goto V_28;
}
break;
case V_15 :
if ( V_4 >= V_6 -> V_10 ) {
V_27 = - V_14 ;
goto V_28;
}
V_4 = V_6 -> V_10 ;
break;
}
V_27 = - V_16 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_12 ) {
V_1 -> V_12 = V_4 ;
V_1 -> V_19 = 0 ;
}
V_27 = V_4 ;
}
V_28:
F_5 ( & V_6 -> V_23 ) ;
return V_27 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_5 )
{
T_1 (* F_11)( struct V_1 * , T_1 , int );
F_11 = F_7 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 && V_1 -> V_30 -> V_31 )
F_11 = V_1 -> V_30 -> V_31 ;
}
return F_11 ( V_1 , V_4 , V_5 ) ;
}
int F_12 ( int V_32 , struct V_1 * V_1 , T_1 * V_33 , T_2 V_34 )
{
struct V_6 * V_6 ;
T_1 V_35 ;
int V_27 = - V_16 ;
V_6 = V_1 -> V_25 . V_26 -> V_22 ;
if ( F_13 ( ( V_36 ) V_34 < 0 ) )
return V_27 ;
V_35 = * V_33 ;
if ( F_13 ( V_35 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_27 ;
if ( V_34 >= - V_35 )
return - V_37 ;
} else if ( F_13 ( ( T_1 ) ( V_35 + V_34 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_27 ;
}
if ( F_13 ( V_6 -> V_38 && F_14 ( V_6 ) ) ) {
V_27 = F_15 (
V_32 == V_39 ? V_40 : V_41 ,
V_6 , V_1 , V_35 , V_34 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_27 = F_16 ( V_1 ,
V_32 == V_39 ? V_42 : V_43 ) ;
if ( V_27 )
return V_27 ;
return V_34 > V_44 ? V_44 : V_34 ;
}
static void F_17 ( struct V_45 * V_46 )
{
F_18 ( V_47 ) ;
if ( ! F_19 ( V_46 ) )
F_20 () ;
else
F_21 ( V_46 ) ;
F_22 ( V_48 ) ;
}
V_36 F_23 ( struct V_1 * V_49 , char T_3 * V_50 , T_2 V_51 , T_1 * V_33 )
{
struct V_52 V_53 = { . V_54 = V_50 , . V_55 = V_51 } ;
struct V_45 V_45 ;
V_36 V_56 ;
F_24 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = V_49 -> V_30 -> V_60 ( & V_45 , & V_53 , 1 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_17 ( & V_45 ) ;
}
if ( - V_62 == V_56 )
V_56 = F_25 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_26 ( struct V_1 * V_1 , char T_3 * V_50 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_56 ;
if ( ! ( V_1 -> V_2 & V_63 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_65 && ! V_1 -> V_30 -> V_60 ) )
return - V_16 ;
if ( F_13 ( ! F_27 ( V_66 , V_50 , V_34 ) ) )
return - V_67 ;
V_56 = F_12 ( V_39 , V_1 , V_35 , V_34 ) ;
if ( V_56 >= 0 ) {
V_34 = V_56 ;
if ( V_1 -> V_30 -> V_65 )
V_56 = V_1 -> V_30 -> V_65 ( V_1 , V_50 , V_34 , V_35 ) ;
else
V_56 = F_23 ( V_1 , V_50 , V_34 , V_35 ) ;
if ( V_56 > 0 ) {
F_28 ( V_1 ) ;
F_29 ( V_68 , V_56 ) ;
}
F_30 ( V_68 ) ;
}
return V_56 ;
}
V_36 F_31 ( struct V_1 * V_49 , const char T_3 * V_50 , T_2 V_51 , T_1 * V_33 )
{
struct V_52 V_53 = { . V_54 = ( void T_3 * ) V_50 , . V_55 = V_51 } ;
struct V_45 V_45 ;
V_36 V_56 ;
F_24 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = V_49 -> V_30 -> V_69 ( & V_45 , & V_53 , 1 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_17 ( & V_45 ) ;
}
if ( - V_62 == V_56 )
V_56 = F_25 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_32 ( struct V_1 * V_1 , const char T_3 * V_50 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_56 ;
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_71 && ! V_1 -> V_30 -> V_69 ) )
return - V_16 ;
if ( F_13 ( ! F_27 ( V_72 , V_50 , V_34 ) ) )
return - V_67 ;
V_56 = F_12 ( V_73 , V_1 , V_35 , V_34 ) ;
if ( V_56 >= 0 ) {
V_34 = V_56 ;
if ( V_1 -> V_30 -> V_71 )
V_56 = V_1 -> V_30 -> V_71 ( V_1 , V_50 , V_34 , V_35 ) ;
else
V_56 = F_31 ( V_1 , V_50 , V_34 , V_35 ) ;
if ( V_56 > 0 ) {
F_33 ( V_1 ) ;
F_34 ( V_68 , V_56 ) ;
}
F_35 ( V_68 ) ;
}
return V_56 ;
}
static inline T_1 F_36 ( struct V_1 * V_1 )
{
return V_1 -> V_12 ;
}
static inline void F_37 ( struct V_1 * V_1 , T_1 V_35 )
{
V_1 -> V_12 = V_35 ;
}
T_4 (F_38)( unsigned int V_74 , char T_3 * V_50 ,
T_2 V_34 , T_1 V_35 )
{
struct V_1 * V_1 ;
V_36 V_56 = - V_64 ;
int V_75 ;
if ( V_35 < 0 )
return - V_16 ;
V_1 = F_39 ( V_74 , & V_75 ) ;
if ( V_1 ) {
V_56 = - V_24 ;
if ( V_1 -> V_2 & V_76 )
V_56 = F_26 ( V_1 , V_50 , V_34 , & V_35 ) ;
F_40 ( V_1 , V_75 ) ;
}
return V_56 ;
}
T_5 long F_41 ( long V_74 , long V_50 , long V_34 , T_1 V_35 )
{
return F_42 ( ( unsigned int ) V_74 , ( char T_3 * ) V_50 ,
( T_2 ) V_34 , V_35 ) ;
}
T_4 (F_43)( unsigned int V_74 , const char T_3 * V_50 ,
T_2 V_34 , T_1 V_35 )
{
struct V_1 * V_1 ;
V_36 V_56 = - V_64 ;
int V_75 ;
if ( V_35 < 0 )
return - V_16 ;
V_1 = F_39 ( V_74 , & V_75 ) ;
if ( V_1 ) {
V_56 = - V_24 ;
if ( V_1 -> V_2 & V_77 )
V_56 = F_32 ( V_1 , V_50 , V_34 , & V_35 ) ;
F_40 ( V_1 , V_75 ) ;
}
return V_56 ;
}
T_5 long F_44 ( long V_74 , long V_50 , long V_34 , T_1 V_35 )
{
return F_45 ( ( unsigned int ) V_74 , ( const char T_3 * ) V_50 ,
( T_2 ) V_34 , V_35 ) ;
}
unsigned long F_46 ( struct V_52 * V_53 , unsigned long V_78 , T_2 V_79 )
{
unsigned long V_80 = 0 ;
T_2 V_51 = 0 ;
while ( V_80 < V_78 ) {
V_80 ++ ;
if ( V_51 + V_53 -> V_55 >= V_79 ) {
V_53 -> V_55 = V_79 - V_51 ;
break;
}
V_51 += V_53 -> V_55 ;
V_53 ++ ;
}
return V_80 ;
}
V_36 F_47 ( struct V_1 * V_49 , const struct V_52 * V_53 ,
unsigned long V_78 , T_2 V_51 , T_1 * V_33 , T_6 F_11 )
{
struct V_45 V_45 ;
V_36 V_56 ;
F_24 ( & V_45 , V_49 ) ;
V_45 . V_57 = * V_33 ;
V_45 . V_58 = V_51 ;
V_45 . V_59 = V_51 ;
for (; ; ) {
V_56 = F_11 ( & V_45 , V_53 , V_78 , V_45 . V_57 ) ;
if ( V_56 != - V_61 )
break;
F_17 ( & V_45 ) ;
}
if ( V_56 == - V_62 )
V_56 = F_25 ( & V_45 ) ;
* V_33 = V_45 . V_57 ;
return V_56 ;
}
V_36 F_48 ( struct V_1 * V_49 , struct V_52 * V_53 ,
unsigned long V_78 , T_1 * V_33 , T_7 F_11 )
{
struct V_52 * V_81 = V_53 ;
V_36 V_56 = 0 ;
while ( V_78 > 0 ) {
void T_3 * V_82 ;
T_2 V_51 ;
V_36 V_83 ;
V_82 = V_81 -> V_54 ;
V_51 = V_81 -> V_55 ;
V_81 ++ ;
V_78 -- ;
V_83 = F_11 ( V_49 , V_82 , V_51 , V_33 ) ;
if ( V_83 < 0 ) {
if ( ! V_56 )
V_56 = V_83 ;
break;
}
V_56 += V_83 ;
if ( V_83 != V_51 )
break;
}
return V_56 ;
}
V_36 F_49 ( int type , const struct V_52 T_3 * V_84 ,
unsigned long V_78 , unsigned long V_85 ,
struct V_52 * V_86 ,
struct V_52 * * V_87 )
{
unsigned long V_80 ;
V_36 V_56 ;
struct V_52 * V_53 = V_86 ;
if ( V_78 == 0 ) {
V_56 = 0 ;
goto V_28;
}
if ( V_78 > V_88 ) {
V_56 = - V_16 ;
goto V_28;
}
if ( V_78 > V_85 ) {
V_53 = F_50 ( V_78 * sizeof( struct V_52 ) , V_89 ) ;
if ( V_53 == NULL ) {
V_56 = - V_90 ;
goto V_28;
}
}
if ( F_51 ( V_53 , V_84 , V_78 * sizeof( * V_84 ) ) ) {
V_56 = - V_67 ;
goto V_28;
}
V_56 = 0 ;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
void T_3 * V_50 = V_53 [ V_80 ] . V_54 ;
V_36 V_51 = ( V_36 ) V_53 [ V_80 ] . V_55 ;
if ( V_51 < 0 ) {
V_56 = - V_16 ;
goto V_28;
}
if ( F_13 ( ! F_27 ( F_52 ( type ) , V_50 , V_51 ) ) ) {
V_56 = - V_67 ;
goto V_28;
}
if ( V_51 > V_44 - V_56 ) {
V_51 = V_44 - V_56 ;
V_53 [ V_80 ] . V_55 = V_51 ;
}
V_56 += V_51 ;
}
V_28:
* V_87 = V_53 ;
return V_56 ;
}
static V_36 F_53 ( int type , struct V_1 * V_1 ,
const struct V_52 T_3 * V_84 ,
unsigned long V_78 , T_1 * V_35 )
{
T_2 V_91 ;
struct V_52 V_92 [ V_93 ] ;
struct V_52 * V_53 = V_92 ;
V_36 V_56 ;
T_7 F_11 ;
T_6 V_94 ;
if ( ! V_1 -> V_30 ) {
V_56 = - V_16 ;
goto V_28;
}
V_56 = F_49 ( type , V_84 , V_78 ,
F_54 ( V_92 ) , V_92 , & V_53 ) ;
if ( V_56 <= 0 )
goto V_28;
V_91 = V_56 ;
V_56 = F_12 ( type , V_1 , V_35 , V_91 ) ;
if ( V_56 < 0 )
goto V_28;
V_94 = NULL ;
if ( type == V_39 ) {
F_11 = V_1 -> V_30 -> V_65 ;
V_94 = V_1 -> V_30 -> V_60 ;
} else {
F_11 = ( T_7 ) V_1 -> V_30 -> V_71 ;
V_94 = V_1 -> V_30 -> V_69 ;
}
if ( V_94 )
V_56 = F_47 ( V_1 , V_53 , V_78 , V_91 ,
V_35 , V_94 ) ;
else
V_56 = F_48 ( V_1 , V_53 , V_78 , V_35 , F_11 ) ;
V_28:
if ( V_53 != V_92 )
F_55 ( V_53 ) ;
if ( ( V_56 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_28 ( V_1 ) ;
else
F_33 ( V_1 ) ;
}
return V_56 ;
}
V_36 F_56 ( struct V_1 * V_1 , const struct V_52 T_3 * V_95 ,
unsigned long V_96 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_63 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_60 && ! V_1 -> V_30 -> V_65 ) )
return - V_16 ;
return F_53 ( V_39 , V_1 , V_95 , V_96 , V_35 ) ;
}
V_36 F_57 ( struct V_1 * V_1 , const struct V_52 T_3 * V_95 ,
unsigned long V_96 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_70 ) )
return - V_64 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_69 && ! V_1 -> V_30 -> V_71 ) )
return - V_16 ;
return F_53 ( V_73 , V_1 , V_95 , V_96 , V_35 ) ;
}
static inline T_1 F_58 ( unsigned long V_97 , unsigned long V_98 )
{
#define F_59 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_97 << F_59 ) << F_59 ) | V_98 ;
}
static V_36 F_60 ( int V_99 , int V_100 , T_1 * V_33 ,
T_2 V_34 , T_1 V_101 )
{
struct V_1 * V_102 , * V_103 ;
struct V_6 * V_104 , * V_105 ;
T_1 V_35 ;
V_36 V_27 ;
int V_106 , V_107 , V_108 ;
V_27 = - V_64 ;
V_102 = F_39 ( V_100 , & V_106 ) ;
if ( ! V_102 )
goto V_28;
if ( ! ( V_102 -> V_2 & V_63 ) )
goto V_109;
V_27 = - V_24 ;
if ( ! V_33 )
V_33 = & V_102 -> V_12 ;
else
if ( ! ( V_102 -> V_2 & V_76 ) )
goto V_109;
V_27 = F_12 ( V_39 , V_102 , V_33 , V_34 ) ;
if ( V_27 < 0 )
goto V_109;
V_34 = V_27 ;
V_27 = - V_64 ;
V_103 = F_39 ( V_99 , & V_107 ) ;
if ( ! V_103 )
goto V_109;
if ( ! ( V_103 -> V_2 & V_70 ) )
goto V_110;
V_27 = - V_16 ;
V_104 = V_102 -> V_25 . V_26 -> V_22 ;
V_105 = V_103 -> V_25 . V_26 -> V_22 ;
V_27 = F_12 ( V_73 , V_103 , & V_103 -> V_12 , V_34 ) ;
if ( V_27 < 0 )
goto V_110;
V_34 = V_27 ;
if ( ! V_101 )
V_101 = F_61 ( V_104 -> V_17 -> V_18 , V_105 -> V_17 -> V_18 ) ;
V_35 = * V_33 ;
if ( F_13 ( V_35 + V_34 > V_101 ) ) {
V_27 = - V_37 ;
if ( V_35 >= V_101 )
goto V_110;
V_34 = V_101 - V_35 ;
}
V_108 = 0 ;
#if 0
if (in_file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_27 = F_62 ( V_102 , V_33 , V_103 , V_34 , V_108 ) ;
if ( V_27 > 0 ) {
F_29 ( V_68 , V_27 ) ;
F_34 ( V_68 , V_27 ) ;
}
F_30 ( V_68 ) ;
F_35 ( V_68 ) ;
if ( * V_33 > V_101 )
V_27 = - V_37 ;
V_110:
F_40 ( V_103 , V_107 ) ;
V_109:
F_40 ( V_102 , V_106 ) ;
V_28:
return V_27 ;
}

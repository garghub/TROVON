static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 = F_2 ( V_3 , V_5 ) ;
if ( V_2 -> V_4 == NULL )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_2 -> V_4 ;
V_2 -> V_9 = V_2 -> V_4 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_2 -> V_8 ;
}
static unsigned F_6 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_8 - V_2 -> V_9 ) % V_2 -> V_7 ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_7 + V_2 -> V_9 - V_2 -> V_8 - 1 ) % V_2 -> V_7 ;
}
static unsigned
F_8 ( struct V_1 * V_2 , const char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_8 ;
if ( V_11 > V_12 ) {
memcpy ( V_2 -> V_8 , V_10 , V_12 ) ;
memcpy ( V_2 -> V_4 , V_10 + V_12 , V_11 - V_12 ) ;
V_2 -> V_8 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_2 -> V_8 , V_10 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_8 += V_11 ;
else
V_2 -> V_8 = V_2 -> V_4 ;
}
return V_11 ;
}
static unsigned
F_9 ( struct V_1 * V_2 , char * V_10 , unsigned V_11 )
{
unsigned V_12 ;
V_12 = F_6 ( V_2 ) ;
if ( V_11 > V_12 )
V_11 = V_12 ;
if ( V_11 == 0 )
return 0 ;
V_12 = V_2 -> V_4 + V_2 -> V_7 - V_2 -> V_9 ;
if ( V_11 > V_12 ) {
memcpy ( V_10 , V_2 -> V_9 , V_12 ) ;
memcpy ( V_10 + V_12 , V_2 -> V_4 , V_11 - V_12 ) ;
V_2 -> V_9 = V_2 -> V_4 + V_11 - V_12 ;
} else {
memcpy ( V_10 , V_2 -> V_9 , V_11 ) ;
if ( V_11 < V_12 )
V_2 -> V_9 += V_11 ;
else
V_2 -> V_9 = V_2 -> V_4 ;
}
return V_11 ;
}
struct V_13 *
F_10 ( struct V_14 * V_15 , unsigned V_12 , T_1 V_16 )
{
struct V_13 * V_17 ;
V_17 = F_11 ( V_15 , V_16 ) ;
if ( V_17 != NULL ) {
V_17 -> V_18 = V_12 ;
V_17 -> V_10 = F_2 ( V_12 , V_16 ) ;
if ( V_17 -> V_10 == NULL ) {
F_12 ( V_15 , V_17 ) ;
return NULL ;
}
}
return V_17 ;
}
void F_13 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
F_4 ( V_17 -> V_10 ) ;
F_12 ( V_15 , V_17 ) ;
}
static unsigned
F_14 ( struct V_19 * V_20 , char * V_21 , unsigned V_3 )
{
unsigned V_12 ;
V_12 = F_6 ( & V_20 -> V_22 ) ;
if ( V_12 < V_3 )
V_3 = V_12 ;
if ( V_3 != 0 )
V_3 = F_9 ( & V_20 -> V_22 , V_21 , V_3 ) ;
return V_3 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_25 ;
struct V_14 * V_26 ;
int V_27 = 0 ;
bool V_28 = false ;
if ( ! V_20 -> V_29 )
return V_27 ;
V_26 = V_20 -> V_29 -> V_26 ;
while ( ! V_20 -> V_30 && ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_12 ;
if ( V_20 -> V_31 >= V_32 )
break;
V_17 = F_17 ( V_24 -> V_33 , struct V_13 , V_34 ) ;
V_12 = F_14 ( V_20 , V_17 -> V_10 , V_26 -> V_35 ) ;
if ( V_12 == 0 ) {
F_18 ( & V_20 -> V_36 ) ;
break;
}
V_28 = true ;
V_17 -> V_18 = V_12 ;
F_19 ( & V_17 -> V_34 ) ;
V_17 -> V_37 = ( F_6 ( & V_20 -> V_22 ) == 0 ) ;
F_20 ( L_1 ,
V_20 -> V_38 , V_12 , * ( ( V_39 * ) V_17 -> V_10 ) ,
* ( ( V_39 * ) V_17 -> V_10 + 1 ) , * ( ( V_39 * ) V_17 -> V_10 + 2 ) ) ;
V_20 -> V_30 = true ;
F_21 ( & V_20 -> V_40 ) ;
V_27 = F_22 ( V_26 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
V_20 -> V_30 = false ;
if ( V_27 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_26 -> V_43 , V_27 ) ;
F_25 ( & V_17 -> V_34 , V_24 ) ;
break;
}
V_20 -> V_31 ++ ;
if ( ! V_20 -> V_29 )
break;
}
if ( V_28 && V_20 -> V_20 . V_44 )
F_26 ( V_20 -> V_20 . V_44 ) ;
return V_27 ;
}
static unsigned F_27 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_45 ;
struct V_14 * V_46 = V_20 -> V_29 -> V_46 ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_27 ;
struct V_47 * V_44 ;
V_44 = V_20 -> V_20 . V_44 ;
if ( ! V_44 )
break;
if ( V_20 -> V_48 >= V_32 )
break;
V_17 = F_17 ( V_24 -> V_33 , struct V_13 , V_34 ) ;
F_19 ( & V_17 -> V_34 ) ;
V_17 -> V_18 = V_46 -> V_35 ;
F_21 ( & V_20 -> V_40 ) ;
V_27 = F_22 ( V_46 , V_17 , V_41 ) ;
F_23 ( & V_20 -> V_40 ) ;
if ( V_27 ) {
F_24 ( L_2 ,
V_42 , L_3 , V_46 -> V_43 , V_27 ) ;
F_25 ( & V_17 -> V_34 , V_24 ) ;
break;
}
V_20 -> V_48 ++ ;
if ( ! V_20 -> V_29 )
break;
}
return V_20 -> V_48 ;
}
static void F_28 ( unsigned long V_49 )
{
struct V_19 * V_20 = ( void * ) V_49 ;
struct V_47 * V_44 ;
struct V_23 * V_50 = & V_20 -> V_51 ;
bool V_52 = false ;
bool V_53 = false ;
F_29 ( & V_20 -> V_40 ) ;
V_44 = V_20 -> V_20 . V_44 ;
while ( ! F_16 ( V_50 ) ) {
struct V_13 * V_17 ;
V_17 = F_30 ( V_50 , struct V_13 , V_34 ) ;
if ( V_44 && F_31 ( V_44 ) )
break;
switch ( V_17 -> V_27 ) {
case - V_54 :
V_52 = true ;
F_20 ( L_4 , V_20 -> V_38 ) ;
break;
default:
F_32 ( L_5 ,
V_20 -> V_38 , V_17 -> V_27 ) ;
case 0 :
break;
}
if ( V_17 -> V_55 && V_44 ) {
char * V_21 = V_17 -> V_10 ;
unsigned V_3 = V_17 -> V_55 ;
unsigned V_56 ;
int V_11 ;
V_56 = V_20 -> V_57 ;
if ( V_56 ) {
V_21 += V_56 ;
V_3 -= V_56 ;
}
V_11 = F_33 ( & V_20 -> V_20 , V_21 ,
V_3 ) ;
if ( V_11 )
V_53 = true ;
if ( V_11 != V_3 ) {
V_20 -> V_57 += V_11 ;
F_20 ( L_6 ,
V_20 -> V_38 , V_11 , V_17 -> V_55 ) ;
break;
}
V_20 -> V_57 = 0 ;
}
F_34 ( & V_17 -> V_34 , & V_20 -> V_45 ) ;
V_20 -> V_48 -- ;
}
if ( V_53 )
F_35 ( & V_20 -> V_20 ) ;
if ( ! F_16 ( V_50 ) && V_44 ) {
if ( ! F_31 ( V_44 ) ) {
if ( V_53 )
F_36 ( & V_20 -> V_58 ) ;
else
F_32 ( L_7 ,
V_20 -> V_38 ) ;
}
}
if ( ! V_52 && V_20 -> V_29 )
F_27 ( V_20 ) ;
F_37 ( & V_20 -> V_40 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_59 ;
F_23 ( & V_20 -> V_40 ) ;
F_39 ( & V_17 -> V_34 , & V_20 -> V_51 ) ;
F_36 ( & V_20 -> V_58 ) ;
F_21 ( & V_20 -> V_40 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_59 ;
F_23 ( & V_20 -> V_40 ) ;
F_25 ( & V_17 -> V_34 , & V_20 -> V_25 ) ;
V_20 -> V_31 -- ;
switch ( V_17 -> V_27 ) {
default:
F_32 ( L_8 ,
V_42 , V_15 -> V_43 , V_17 -> V_27 ) ;
case 0 :
F_15 ( V_20 ) ;
break;
case - V_54 :
F_20 ( L_9 , V_42 , V_15 -> V_43 ) ;
break;
}
F_21 ( & V_20 -> V_40 ) ;
}
static void F_41 ( struct V_14 * V_15 , struct V_23 * V_60 ,
int * V_61 )
{
struct V_13 * V_17 ;
while ( ! F_16 ( V_60 ) ) {
V_17 = F_17 ( V_60 -> V_33 , struct V_13 , V_34 ) ;
F_19 ( & V_17 -> V_34 ) ;
F_13 ( V_15 , V_17 ) ;
if ( V_61 )
( * V_61 ) -- ;
}
}
static int F_42 ( struct V_14 * V_15 , struct V_23 * V_60 ,
void (* F_43)( struct V_14 * , struct V_13 * ) ,
int * V_61 )
{
int V_62 ;
struct V_13 * V_17 ;
int V_56 = V_61 ? V_32 - * V_61 : V_32 ;
for ( V_62 = 0 ; V_62 < V_56 ; V_62 ++ ) {
V_17 = F_10 ( V_15 , V_15 -> V_35 , V_41 ) ;
if ( ! V_17 )
return F_16 ( V_60 ) ? - V_6 : 0 ;
V_17 -> V_63 = F_43 ;
F_39 ( & V_17 -> V_34 , V_60 ) ;
if ( V_61 )
( * V_61 ) ++ ;
}
return 0 ;
}
static int F_44 ( struct V_19 * V_20 )
{
struct V_23 * V_60 = & V_20 -> V_45 ;
struct V_14 * V_15 = V_20 -> V_29 -> V_46 ;
int V_27 ;
unsigned V_64 ;
V_27 = F_42 ( V_15 , V_60 , F_38 ,
& V_20 -> V_65 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_42 ( V_20 -> V_29 -> V_26 , & V_20 -> V_25 ,
F_40 , & V_20 -> V_66 ) ;
if ( V_27 ) {
F_41 ( V_15 , V_60 , & V_20 -> V_65 ) ;
return V_27 ;
}
V_20 -> V_57 = 0 ;
V_64 = F_27 ( V_20 ) ;
if ( V_64 ) {
F_26 ( V_20 -> V_20 . V_44 ) ;
} else {
F_41 ( V_15 , V_60 , & V_20 -> V_65 ) ;
F_41 ( V_20 -> V_29 -> V_26 , & V_20 -> V_25 ,
& V_20 -> V_66 ) ;
V_27 = - V_67 ;
}
return V_27 ;
}
static int F_45 ( struct V_47 * V_44 , struct V_68 * V_68 )
{
int V_38 = V_44 -> V_69 ;
struct V_19 * V_20 ;
int V_27 ;
do {
F_46 ( & V_70 [ V_38 ] . V_71 ) ;
V_20 = V_70 [ V_38 ] . V_20 ;
if ( ! V_20 )
V_27 = - V_72 ;
else {
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 ) {
V_27 = 0 ;
V_20 -> V_20 . V_11 ++ ;
} else if ( V_20 -> V_73 ) {
V_27 = - V_74 ;
} else {
V_27 = - V_75 ;
V_20 -> V_73 = true ;
}
F_37 ( & V_20 -> V_40 ) ;
}
F_47 ( & V_70 [ V_38 ] . V_71 ) ;
switch ( V_27 ) {
default:
return V_27 ;
case - V_75 :
break;
case - V_74 :
F_48 ( 1 ) ;
break;
}
} while ( V_27 != - V_75 );
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_22 . V_4 == NULL ) {
F_37 ( & V_20 -> V_40 ) ;
V_27 = F_1 ( & V_20 -> V_22 , V_76 ) ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_27 ) {
F_24 ( L_10 ,
V_20 -> V_38 , V_44 , V_68 ) ;
V_20 -> V_73 = false ;
goto V_77;
}
}
V_44 -> V_59 = V_20 ;
V_20 -> V_20 . V_44 = V_44 ;
V_20 -> V_20 . V_11 = 1 ;
V_20 -> V_73 = false ;
if ( V_20 -> V_29 ) {
struct V_78 * V_79 = V_20 -> V_29 ;
F_24 ( L_11 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_79 -> V_80 )
V_79 -> V_80 ( V_79 ) ;
}
F_24 ( L_12 , V_20 -> V_38 , V_44 , V_68 ) ;
V_27 = 0 ;
V_77:
F_37 ( & V_20 -> V_40 ) ;
return V_27 ;
}
static int F_49 ( struct V_19 * V_81 )
{
int V_82 ;
F_29 ( & V_81 -> V_40 ) ;
V_82 = ( V_81 -> V_29 == NULL ) || ! F_6 ( & V_81 -> V_22 ) ;
F_37 ( & V_81 -> V_40 ) ;
return V_82 ;
}
static void F_50 ( struct V_47 * V_44 , struct V_68 * V_68 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
struct V_78 * V_79 ;
F_29 ( & V_20 -> V_40 ) ;
if ( V_20 -> V_20 . V_11 != 1 ) {
if ( V_20 -> V_20 . V_11 == 0 )
F_51 ( 1 ) ;
else
-- V_20 -> V_20 . V_11 ;
goto exit;
}
F_24 ( L_13 , V_20 -> V_38 , V_44 , V_68 ) ;
V_20 -> V_73 = true ;
V_20 -> V_20 . V_11 = 0 ;
V_79 = V_20 -> V_29 ;
if ( V_79 && V_79 -> V_52 )
V_79 -> V_52 ( V_79 ) ;
if ( F_6 ( & V_20 -> V_22 ) > 0 && V_79 ) {
F_37 ( & V_20 -> V_40 ) ;
F_52 ( V_20 -> V_36 ,
F_49 ( V_20 ) ,
V_83 * V_84 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_79 = V_20 -> V_29 ;
}
if ( V_79 == NULL )
F_3 ( & V_20 -> V_22 ) ;
else
F_5 ( & V_20 -> V_22 ) ;
V_20 -> V_20 . V_44 = NULL ;
V_20 -> V_73 = false ;
F_24 ( L_14 ,
V_20 -> V_38 , V_44 , V_68 ) ;
F_53 ( & V_20 -> V_85 ) ;
exit:
F_37 ( & V_20 -> V_40 ) ;
}
static int F_54 ( struct V_47 * V_44 , const unsigned char * V_10 , int V_11 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
F_20 ( L_15 ,
V_20 -> V_38 , V_44 , V_11 ) ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
if ( V_11 )
V_11 = F_8 ( & V_20 -> V_22 , V_10 , V_11 ) ;
if ( V_20 -> V_29 )
F_15 ( V_20 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
return V_11 ;
}
static int F_57 ( struct V_47 * V_44 , unsigned char V_87 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
int V_27 ;
F_20 ( L_16 ,
V_20 -> V_38 , V_44 , V_87 , F_58 ( 0 ) ) ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
V_27 = F_8 ( & V_20 -> V_22 , & V_87 , 1 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
return V_27 ;
}
static void F_59 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
F_20 ( L_17 , V_20 -> V_38 , V_44 ) ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
if ( V_20 -> V_29 )
F_15 ( V_20 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
}
static int F_60 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
int V_88 = 0 ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
if ( V_20 -> V_29 )
V_88 = F_7 ( & V_20 -> V_22 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
F_20 ( L_18 ,
V_20 -> V_38 , V_44 , V_88 ) ;
return V_88 ;
}
static int F_61 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
int V_89 = 0 ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
V_89 = F_6 ( & V_20 -> V_22 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
F_20 ( L_19 ,
V_20 -> V_38 , V_44 , V_89 ) ;
return V_89 ;
}
static void F_62 ( struct V_47 * V_44 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
unsigned long V_86 ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
if ( V_20 -> V_29 ) {
F_36 ( & V_20 -> V_58 ) ;
F_20 ( L_20 , V_20 -> V_38 ) ;
}
F_56 ( & V_20 -> V_40 , V_86 ) ;
}
static int F_63 ( struct V_47 * V_44 , int V_90 )
{
struct V_19 * V_20 = V_44 -> V_59 ;
int V_27 = 0 ;
struct V_78 * V_79 ;
F_20 ( L_21 ,
V_20 -> V_38 , V_90 ) ;
F_29 ( & V_20 -> V_40 ) ;
V_79 = V_20 -> V_29 ;
if ( V_79 && V_79 -> V_91 )
V_27 = V_79 -> V_91 ( V_79 , V_90 ) ;
F_37 ( & V_20 -> V_40 ) ;
return V_27 ;
}
static struct V_13 * F_64 ( struct V_14 * V_15 )
{
struct V_13 * V_17 = F_11 ( V_15 , V_41 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_10 = F_2 ( V_15 -> V_35 , V_41 ) ;
if ( ! V_17 -> V_10 ) {
F_12 ( V_15 , V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_65 ( struct V_13 * V_17 , struct V_14 * V_15 )
{
if ( ! V_17 )
return;
F_4 ( V_17 -> V_10 ) ;
F_12 ( V_15 , V_17 ) ;
}
static void F_66 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_92 * V_93 = & V_92 ;
switch ( V_17 -> V_27 ) {
default:
F_32 ( L_8 ,
V_42 , V_15 -> V_43 , V_17 -> V_27 ) ;
case 0 :
F_23 ( & V_93 -> V_94 ) ;
V_93 -> V_95 = 0 ;
F_21 ( & V_93 -> V_94 ) ;
F_67 ( V_93 -> V_96 ) ;
break;
case - V_54 :
F_20 ( L_9 , V_42 , V_15 -> V_43 ) ;
break;
}
}
static int F_68 ( int V_38 )
{
struct V_92 * V_93 = & V_92 ;
struct V_19 * V_20 ;
struct V_14 * V_15 ;
if ( V_38 != V_97 . V_69 ) {
F_69 ( L_22 ,
V_42 , V_38 ) ;
return - V_98 ;
}
V_20 = V_70 [ V_38 ] . V_20 ;
V_15 = V_20 -> V_29 -> V_26 ;
if ( ! V_93 -> V_99 ) {
V_93 -> V_99 = F_64 ( V_15 ) ;
if ( ! V_93 -> V_99 )
return - V_6 ;
V_93 -> V_99 -> V_63 = F_66 ;
}
V_93 -> V_20 = V_20 ;
F_23 ( & V_93 -> V_94 ) ;
V_93 -> V_95 = 0 ;
F_21 ( & V_93 -> V_94 ) ;
F_20 ( L_23 , V_38 ) ;
return 0 ;
}
static void F_70 ( struct V_14 * V_15 )
{
struct V_92 * V_93 = & V_92 ;
struct V_13 * V_17 = V_93 -> V_99 ;
F_65 ( V_17 , V_15 ) ;
V_93 -> V_99 = NULL ;
}
static int F_71 ( void * V_100 )
{
struct V_92 * V_93 = & V_92 ;
struct V_19 * V_20 ;
struct V_13 * V_17 ;
struct V_14 * V_15 ;
int V_101 , V_102 , V_11 , V_3 ;
do {
V_20 = V_93 -> V_20 ;
F_72 ( V_103 ) ;
if ( ! V_20 || ! V_20 -> V_29
|| ! V_20 -> V_29 -> V_26 || ! V_93 -> V_99 )
goto V_104;
V_17 = V_93 -> V_99 ;
V_15 = V_20 -> V_29 -> V_26 ;
F_29 ( & V_93 -> V_94 ) ;
V_11 = F_6 ( & V_93 -> V_105 ) ;
V_3 = V_15 -> V_35 ;
if ( V_11 > 0 && ! V_93 -> V_95 ) {
F_72 ( V_106 ) ;
if ( V_11 < V_3 )
V_3 = V_11 ;
V_101 = F_9 ( & V_93 -> V_105 , V_17 -> V_10 , V_3 ) ;
V_17 -> V_18 = V_101 ;
F_21 ( & V_93 -> V_94 ) ;
V_102 = F_22 ( V_15 , V_17 , V_41 ) ;
F_23 ( & V_93 -> V_94 ) ;
if ( V_102 < 0 )
V_93 -> V_95 = 0 ;
else
V_93 -> V_95 = 1 ;
F_37 ( & V_93 -> V_94 ) ;
} else {
F_37 ( & V_93 -> V_94 ) ;
V_104:
if ( F_73 () ) {
F_72 ( V_106 ) ;
break;
}
F_74 () ;
}
} while ( 1 );
return 0 ;
}
static int F_75 ( struct V_107 * V_108 , char * V_109 )
{
struct V_92 * V_93 = & V_92 ;
int V_27 ;
V_93 -> V_20 = NULL ;
V_93 -> V_99 = NULL ;
V_93 -> V_95 = 0 ;
F_76 ( & V_93 -> V_94 ) ;
V_27 = F_1 ( & V_93 -> V_105 , V_110 ) ;
if ( V_27 ) {
F_69 ( L_24 , V_42 ) ;
return V_27 ;
}
V_93 -> V_96 = F_77 ( F_71 ,
V_108 , L_25 ) ;
if ( F_78 ( V_93 -> V_96 ) ) {
F_69 ( L_26 , V_42 ) ;
F_3 ( & V_93 -> V_105 ) ;
return F_79 ( V_93 -> V_96 ) ;
}
F_67 ( V_93 -> V_96 ) ;
return 0 ;
}
static void F_80 ( struct V_107 * V_108 ,
const char * V_10 , unsigned V_11 )
{
struct V_92 * V_93 = & V_92 ;
unsigned long V_86 ;
F_55 ( & V_93 -> V_94 , V_86 ) ;
F_8 ( & V_93 -> V_105 , V_10 , V_11 ) ;
F_56 ( & V_93 -> V_94 , V_86 ) ;
F_67 ( V_93 -> V_96 ) ;
}
static struct V_111 * F_81 ( struct V_107 * V_108 , int * V_69 )
{
struct V_111 * * V_81 = (struct V_111 * * ) V_108 -> V_100 ;
if ( ! * V_81 )
return NULL ;
* V_69 = V_108 -> V_69 ;
return * V_81 ;
}
static void F_82 ( void )
{
F_83 ( & V_97 ) ;
}
static void F_84 ( void )
{
struct V_92 * V_93 = & V_92 ;
F_85 ( & V_97 ) ;
if ( ! F_86 ( V_93 -> V_96 ) )
F_87 ( V_93 -> V_96 ) ;
F_3 ( & V_93 -> V_105 ) ;
}
static int F_68 ( int V_38 )
{
return 0 ;
}
static void F_70 ( struct V_14 * V_15 )
{
}
static void F_82 ( void )
{
}
static void F_84 ( void )
{
}
static int
F_88 ( unsigned V_38 , struct V_112 * V_113 )
{
struct V_19 * V_20 ;
int V_102 = 0 ;
F_46 ( & V_70 [ V_38 ] . V_71 ) ;
if ( V_70 [ V_38 ] . V_20 ) {
V_102 = - V_74 ;
goto V_46;
}
V_20 = F_89 ( sizeof( struct V_19 ) , V_5 ) ;
if ( V_20 == NULL ) {
V_102 = - V_6 ;
goto V_46;
}
F_90 ( & V_20 -> V_20 ) ;
F_76 ( & V_20 -> V_40 ) ;
F_91 ( & V_20 -> V_36 ) ;
F_91 ( & V_20 -> V_85 ) ;
F_92 ( & V_20 -> V_58 , F_28 , ( unsigned long ) V_20 ) ;
F_93 ( & V_20 -> V_45 ) ;
F_93 ( & V_20 -> V_51 ) ;
F_93 ( & V_20 -> V_25 ) ;
V_20 -> V_38 = V_38 ;
V_20 -> V_114 = * V_113 ;
V_70 [ V_38 ] . V_20 = V_20 ;
V_46:
F_47 ( & V_70 [ V_38 ] . V_71 ) ;
return V_102 ;
}
static int F_94 ( struct V_19 * V_20 )
{
int V_82 ;
F_29 ( & V_20 -> V_40 ) ;
V_82 = ( V_20 -> V_20 . V_11 == 0 ) && ! V_20 -> V_73 ;
F_37 ( & V_20 -> V_40 ) ;
return V_82 ;
}
static void F_95 ( struct V_19 * V_20 )
{
F_96 ( & V_20 -> V_58 ) ;
F_97 ( V_20 -> V_85 , F_94 ( V_20 ) ) ;
F_51 ( V_20 -> V_29 != NULL ) ;
F_98 ( & V_20 -> V_20 ) ;
F_4 ( V_20 ) ;
}
void F_99 ( unsigned char V_38 )
{
struct V_19 * V_20 ;
F_46 ( & V_70 [ V_38 ] . V_71 ) ;
if ( F_51 ( ! V_70 [ V_38 ] . V_20 ) ) {
F_47 ( & V_70 [ V_38 ] . V_71 ) ;
return;
}
V_20 = V_70 [ V_38 ] . V_20 ;
V_70 [ V_38 ] . V_20 = NULL ;
F_47 ( & V_70 [ V_38 ] . V_71 ) ;
F_95 ( V_20 ) ;
F_100 ( V_115 , V_38 ) ;
F_84 () ;
}
int F_101 ( unsigned char * V_116 )
{
struct V_112 V_113 ;
struct V_117 * V_118 ;
int V_102 ;
int V_38 ;
V_113 . V_119 = F_102 ( 9600 ) ;
V_113 . V_120 = 8 ;
V_113 . V_121 = V_122 ;
V_113 . V_123 = V_124 ;
for ( V_38 = 0 ; V_38 < V_125 ; V_38 ++ ) {
V_102 = F_88 ( V_38 , & V_113 ) ;
if ( V_102 == - V_74 )
continue;
if ( V_102 )
return V_102 ;
break;
}
if ( V_102 )
return V_102 ;
V_118 = F_103 ( & V_70 [ V_38 ] . V_20 -> V_20 ,
V_115 , V_38 , NULL ) ;
if ( F_78 ( V_118 ) ) {
struct V_19 * V_20 ;
F_69 ( L_27 ,
V_42 , V_38 , F_79 ( V_118 ) ) ;
V_102 = F_79 ( V_118 ) ;
V_20 = V_70 [ V_38 ] . V_20 ;
V_70 [ V_38 ] . V_20 = NULL ;
F_95 ( V_20 ) ;
goto V_126;
}
* V_116 = V_38 ;
F_82 () ;
V_126:
return V_102 ;
}
int F_104 ( struct V_78 * V_79 , V_39 V_38 )
{
struct V_19 * V_20 ;
unsigned long V_86 ;
int V_27 ;
if ( V_38 >= V_125 )
return - V_98 ;
V_20 = V_70 [ V_38 ] . V_20 ;
if ( ! V_20 ) {
F_69 ( L_28 , V_38 ) ;
return - V_127 ;
}
if ( V_20 -> V_29 ) {
F_69 ( L_29 , V_38 ) ;
return - V_74 ;
}
V_27 = F_105 ( V_79 -> V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
V_79 -> V_26 -> V_59 = V_20 ;
V_27 = F_105 ( V_79 -> V_46 ) ;
if ( V_27 < 0 )
goto V_128;
V_79 -> V_46 -> V_59 = V_20 ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
V_79 -> V_129 = V_20 ;
V_20 -> V_29 = V_79 ;
V_79 -> V_114 = V_20 -> V_114 ;
if ( V_20 -> V_20 . V_11 ) {
F_24 ( L_30 , V_20 -> V_38 ) ;
F_44 ( V_20 ) ;
if ( V_79 -> V_80 )
V_79 -> V_80 ( V_79 ) ;
} else {
if ( V_79 -> V_52 )
V_79 -> V_52 ( V_79 ) ;
}
V_27 = F_68 ( V_38 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
return V_27 ;
V_128:
F_106 ( V_79 -> V_26 ) ;
return V_27 ;
}
void F_107 ( struct V_78 * V_79 )
{
struct V_19 * V_20 = V_79 -> V_129 ;
unsigned long V_86 ;
if ( ! V_20 )
return;
F_55 ( & V_20 -> V_40 , V_86 ) ;
V_20 -> V_114 = V_79 -> V_114 ;
V_20 -> V_29 = NULL ;
V_79 -> V_129 = NULL ;
if ( V_20 -> V_20 . V_11 > 0 || V_20 -> V_73 ) {
F_18 ( & V_20 -> V_36 ) ;
if ( V_20 -> V_20 . V_44 )
F_108 ( V_20 -> V_20 . V_44 ) ;
}
F_56 ( & V_20 -> V_40 , V_86 ) ;
F_106 ( V_79 -> V_46 ) ;
F_106 ( V_79 -> V_26 ) ;
F_55 ( & V_20 -> V_40 , V_86 ) ;
if ( V_20 -> V_20 . V_11 == 0 && ! V_20 -> V_73 )
F_3 ( & V_20 -> V_22 ) ;
F_41 ( V_79 -> V_46 , & V_20 -> V_45 , NULL ) ;
F_41 ( V_79 -> V_46 , & V_20 -> V_51 , NULL ) ;
F_41 ( V_79 -> V_26 , & V_20 -> V_25 , NULL ) ;
V_20 -> V_65 = V_20 -> V_48 =
V_20 -> V_66 = V_20 -> V_31 = 0 ;
F_70 ( V_79 -> V_26 ) ;
F_56 ( & V_20 -> V_40 , V_86 ) ;
}
static int F_109 ( void )
{
unsigned V_62 ;
int V_27 ;
V_115 = F_110 ( V_125 ) ;
if ( ! V_115 )
return - V_6 ;
V_115 -> V_130 = L_31 ;
V_115 -> V_43 = L_32 ;
V_115 -> type = V_131 ;
V_115 -> V_132 = V_133 ;
V_115 -> V_86 = V_134 | V_135 ;
V_115 -> V_136 = V_137 ;
V_115 -> V_136 . V_138 =
V_139 | V_140 | V_141 | V_142 | V_143 ;
V_115 -> V_136 . V_144 = 9600 ;
V_115 -> V_136 . V_145 = 9600 ;
F_111 ( V_115 , & V_146 ) ;
for ( V_62 = 0 ; V_62 < V_125 ; V_62 ++ )
F_112 ( & V_70 [ V_62 ] . V_71 ) ;
V_27 = F_113 ( V_115 ) ;
if ( V_27 ) {
F_69 ( L_33 ,
V_42 , V_27 ) ;
goto V_147;
}
F_24 ( L_34 , V_42 ,
V_125 ,
( V_125 == 1 ) ? L_35 : L_36 ) ;
return V_27 ;
V_147:
F_114 ( V_115 ) ;
V_115 = NULL ;
return V_27 ;
}
static void F_115 ( void )
{
F_116 ( V_115 ) ;
F_114 ( V_115 ) ;
V_115 = NULL ;
}

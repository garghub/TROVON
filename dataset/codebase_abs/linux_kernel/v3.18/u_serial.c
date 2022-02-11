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
struct V_14 * V_26 = V_20 -> V_27 -> V_26 ;
int V_28 = 0 ;
bool V_29 = false ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_12 ;
if ( V_20 -> V_30 >= V_31 )
break;
V_17 = F_17 ( V_24 -> V_32 , struct V_13 , V_33 ) ;
V_12 = F_14 ( V_20 , V_17 -> V_10 , V_26 -> V_34 ) ;
if ( V_12 == 0 ) {
F_18 ( & V_20 -> V_35 ) ;
break;
}
V_29 = true ;
V_17 -> V_18 = V_12 ;
F_19 ( & V_17 -> V_33 ) ;
V_17 -> V_36 = ( F_6 ( & V_20 -> V_22 ) == 0 ) ;
F_20 ( L_1 ,
V_20 -> V_37 , V_12 , * ( ( V_38 * ) V_17 -> V_10 ) ,
* ( ( V_38 * ) V_17 -> V_10 + 1 ) , * ( ( V_38 * ) V_17 -> V_10 + 2 ) ) ;
F_21 ( & V_20 -> V_39 ) ;
V_28 = F_22 ( V_26 , V_17 , V_40 ) ;
F_23 ( & V_20 -> V_39 ) ;
if ( V_28 ) {
F_24 ( L_2 ,
V_41 , L_3 , V_26 -> V_42 , V_28 ) ;
F_25 ( & V_17 -> V_33 , V_24 ) ;
break;
}
V_20 -> V_30 ++ ;
if ( ! V_20 -> V_27 )
break;
}
if ( V_29 && V_20 -> V_20 . V_43 )
F_26 ( V_20 -> V_20 . V_43 ) ;
return V_28 ;
}
static unsigned F_27 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = & V_20 -> V_44 ;
struct V_14 * V_45 = V_20 -> V_27 -> V_45 ;
while ( ! F_16 ( V_24 ) ) {
struct V_13 * V_17 ;
int V_28 ;
struct V_46 * V_43 ;
V_43 = V_20 -> V_20 . V_43 ;
if ( ! V_43 )
break;
if ( V_20 -> V_47 >= V_31 )
break;
V_17 = F_17 ( V_24 -> V_32 , struct V_13 , V_33 ) ;
F_19 ( & V_17 -> V_33 ) ;
V_17 -> V_18 = V_45 -> V_34 ;
F_21 ( & V_20 -> V_39 ) ;
V_28 = F_22 ( V_45 , V_17 , V_40 ) ;
F_23 ( & V_20 -> V_39 ) ;
if ( V_28 ) {
F_24 ( L_2 ,
V_41 , L_3 , V_45 -> V_42 , V_28 ) ;
F_25 ( & V_17 -> V_33 , V_24 ) ;
break;
}
V_20 -> V_47 ++ ;
if ( ! V_20 -> V_27 )
break;
}
return V_20 -> V_47 ;
}
static void F_28 ( unsigned long V_48 )
{
struct V_19 * V_20 = ( void * ) V_48 ;
struct V_46 * V_43 ;
struct V_23 * V_49 = & V_20 -> V_50 ;
bool V_51 = false ;
bool V_52 = false ;
F_29 ( & V_20 -> V_39 ) ;
V_43 = V_20 -> V_20 . V_43 ;
while ( ! F_16 ( V_49 ) ) {
struct V_13 * V_17 ;
V_17 = F_30 ( V_49 , struct V_13 , V_33 ) ;
if ( V_43 && F_31 ( V_53 , & V_43 -> V_54 ) )
break;
switch ( V_17 -> V_28 ) {
case - V_55 :
V_51 = true ;
F_20 ( L_4 , V_20 -> V_37 ) ;
break;
default:
F_32 ( L_5 ,
V_20 -> V_37 , V_17 -> V_28 ) ;
case 0 :
break;
}
if ( V_17 -> V_56 ) {
char * V_21 = V_17 -> V_10 ;
unsigned V_3 = V_17 -> V_56 ;
unsigned V_57 ;
int V_11 ;
V_57 = V_20 -> V_58 ;
if ( V_57 ) {
V_21 += V_57 ;
V_3 -= V_57 ;
}
V_11 = F_33 ( & V_20 -> V_20 , V_21 ,
V_3 ) ;
if ( V_11 )
V_52 = true ;
if ( V_11 != V_3 ) {
V_20 -> V_58 += V_11 ;
F_20 ( L_6 ,
V_20 -> V_37 , V_11 , V_17 -> V_56 ) ;
break;
}
V_20 -> V_58 = 0 ;
}
F_34 ( & V_17 -> V_33 , & V_20 -> V_44 ) ;
V_20 -> V_47 -- ;
}
if ( V_52 )
F_35 ( & V_20 -> V_20 ) ;
if ( ! F_16 ( V_49 ) && V_43 ) {
if ( ! F_31 ( V_53 , & V_43 -> V_54 ) ) {
if ( V_52 )
F_36 ( & V_20 -> V_59 ) ;
else
F_32 ( L_7 ,
V_20 -> V_37 ) ;
}
}
if ( ! V_51 && V_20 -> V_27 )
F_27 ( V_20 ) ;
F_37 ( & V_20 -> V_39 ) ;
}
static void F_38 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_60 ;
F_23 ( & V_20 -> V_39 ) ;
F_39 ( & V_17 -> V_33 , & V_20 -> V_50 ) ;
F_36 ( & V_20 -> V_59 ) ;
F_21 ( & V_20 -> V_39 ) ;
}
static void F_40 ( struct V_14 * V_15 , struct V_13 * V_17 )
{
struct V_19 * V_20 = V_15 -> V_60 ;
F_23 ( & V_20 -> V_39 ) ;
F_25 ( & V_17 -> V_33 , & V_20 -> V_25 ) ;
V_20 -> V_30 -- ;
switch ( V_17 -> V_28 ) {
default:
F_41 ( L_8 ,
V_41 , V_15 -> V_42 , V_17 -> V_28 ) ;
case 0 :
F_15 ( V_20 ) ;
break;
case - V_55 :
F_20 ( L_9 , V_41 , V_15 -> V_42 ) ;
break;
}
F_21 ( & V_20 -> V_39 ) ;
}
static void F_42 ( struct V_14 * V_15 , struct V_23 * V_61 ,
int * V_62 )
{
struct V_13 * V_17 ;
while ( ! F_16 ( V_61 ) ) {
V_17 = F_17 ( V_61 -> V_32 , struct V_13 , V_33 ) ;
F_19 ( & V_17 -> V_33 ) ;
F_13 ( V_15 , V_17 ) ;
if ( V_62 )
( * V_62 ) -- ;
}
}
static int F_43 ( struct V_14 * V_15 , struct V_23 * V_61 ,
void (* F_44)( struct V_14 * , struct V_13 * ) ,
int * V_62 )
{
int V_63 ;
struct V_13 * V_17 ;
int V_57 = V_62 ? V_31 - * V_62 : V_31 ;
for ( V_63 = 0 ; V_63 < V_57 ; V_63 ++ ) {
V_17 = F_10 ( V_15 , V_15 -> V_34 , V_40 ) ;
if ( ! V_17 )
return F_16 ( V_61 ) ? - V_6 : 0 ;
V_17 -> V_64 = F_44 ;
F_39 ( & V_17 -> V_33 , V_61 ) ;
if ( V_62 )
( * V_62 ) ++ ;
}
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
struct V_23 * V_61 = & V_20 -> V_44 ;
struct V_14 * V_15 = V_20 -> V_27 -> V_45 ;
int V_28 ;
unsigned V_65 ;
V_28 = F_43 ( V_15 , V_61 , F_38 ,
& V_20 -> V_66 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_43 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
F_40 , & V_20 -> V_67 ) ;
if ( V_28 ) {
F_42 ( V_15 , V_61 , & V_20 -> V_66 ) ;
return V_28 ;
}
V_20 -> V_58 = 0 ;
V_65 = F_27 ( V_20 ) ;
if ( V_65 ) {
F_26 ( V_20 -> V_20 . V_43 ) ;
} else {
F_42 ( V_15 , V_61 , & V_20 -> V_66 ) ;
F_42 ( V_20 -> V_27 -> V_26 , & V_20 -> V_25 ,
& V_20 -> V_67 ) ;
V_28 = - V_68 ;
}
return V_28 ;
}
static int F_46 ( struct V_46 * V_43 , struct V_69 * V_69 )
{
int V_37 = V_43 -> V_70 ;
struct V_19 * V_20 ;
int V_28 ;
do {
F_47 ( & V_71 [ V_37 ] . V_72 ) ;
V_20 = V_71 [ V_37 ] . V_20 ;
if ( ! V_20 )
V_28 = - V_73 ;
else {
F_29 ( & V_20 -> V_39 ) ;
if ( V_20 -> V_20 . V_11 ) {
V_28 = 0 ;
V_20 -> V_20 . V_11 ++ ;
} else if ( V_20 -> V_74 ) {
V_28 = - V_75 ;
} else {
V_28 = - V_76 ;
V_20 -> V_74 = true ;
}
F_37 ( & V_20 -> V_39 ) ;
}
F_48 ( & V_71 [ V_37 ] . V_72 ) ;
switch ( V_28 ) {
default:
return V_28 ;
case - V_76 :
break;
case - V_75 :
F_49 ( 1 ) ;
break;
}
} while ( V_28 != - V_76 );
F_29 ( & V_20 -> V_39 ) ;
if ( V_20 -> V_22 . V_4 == NULL ) {
F_37 ( & V_20 -> V_39 ) ;
V_28 = F_1 ( & V_20 -> V_22 , V_77 ) ;
F_29 ( & V_20 -> V_39 ) ;
if ( V_28 ) {
F_24 ( L_10 ,
V_20 -> V_37 , V_43 , V_69 ) ;
V_20 -> V_74 = false ;
goto V_78;
}
}
V_43 -> V_60 = V_20 ;
V_20 -> V_20 . V_43 = V_43 ;
V_20 -> V_20 . V_11 = 1 ;
V_20 -> V_74 = false ;
if ( V_20 -> V_27 ) {
struct V_79 * V_80 = V_20 -> V_27 ;
F_24 ( L_11 , V_20 -> V_37 ) ;
F_45 ( V_20 ) ;
if ( V_80 -> V_81 )
V_80 -> V_81 ( V_80 ) ;
}
F_24 ( L_12 , V_20 -> V_37 , V_43 , V_69 ) ;
V_28 = 0 ;
V_78:
F_37 ( & V_20 -> V_39 ) ;
return V_28 ;
}
static int F_50 ( struct V_19 * V_82 )
{
int V_83 ;
F_29 ( & V_82 -> V_39 ) ;
V_83 = ( V_82 -> V_27 == NULL ) || ! F_6 ( & V_82 -> V_22 ) ;
F_37 ( & V_82 -> V_39 ) ;
return V_83 ;
}
static void F_51 ( struct V_46 * V_43 , struct V_69 * V_69 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
struct V_79 * V_80 ;
F_29 ( & V_20 -> V_39 ) ;
if ( V_20 -> V_20 . V_11 != 1 ) {
if ( V_20 -> V_20 . V_11 == 0 )
F_52 ( 1 ) ;
else
-- V_20 -> V_20 . V_11 ;
goto exit;
}
F_24 ( L_13 , V_20 -> V_37 , V_43 , V_69 ) ;
V_20 -> V_74 = true ;
V_20 -> V_20 . V_11 = 0 ;
V_80 = V_20 -> V_27 ;
if ( V_80 && V_80 -> V_51 )
V_80 -> V_51 ( V_80 ) ;
if ( F_6 ( & V_20 -> V_22 ) > 0 && V_80 ) {
F_37 ( & V_20 -> V_39 ) ;
F_53 ( V_20 -> V_35 ,
F_50 ( V_20 ) ,
V_84 * V_85 ) ;
F_29 ( & V_20 -> V_39 ) ;
V_80 = V_20 -> V_27 ;
}
if ( V_80 == NULL )
F_3 ( & V_20 -> V_22 ) ;
else
F_5 ( & V_20 -> V_22 ) ;
V_43 -> V_60 = NULL ;
V_20 -> V_20 . V_43 = NULL ;
V_20 -> V_74 = false ;
F_24 ( L_14 ,
V_20 -> V_37 , V_43 , V_69 ) ;
F_54 ( & V_20 -> V_20 . V_86 ) ;
exit:
F_37 ( & V_20 -> V_39 ) ;
}
static int F_55 ( struct V_46 * V_43 , const unsigned char * V_10 , int V_11 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
int V_28 ;
F_20 ( L_15 ,
V_20 -> V_37 , V_43 , V_11 ) ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
if ( V_11 )
V_11 = F_8 ( & V_20 -> V_22 , V_10 , V_11 ) ;
if ( V_20 -> V_27 )
V_28 = F_15 ( V_20 ) ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
return V_11 ;
}
static int F_58 ( struct V_46 * V_43 , unsigned char V_87 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
int V_28 ;
F_20 ( L_16 ,
V_20 -> V_37 , V_43 , V_87 , F_59 ( 0 ) ) ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
V_28 = F_8 ( & V_20 -> V_22 , & V_87 , 1 ) ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
return V_28 ;
}
static void F_60 ( struct V_46 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
F_20 ( L_17 , V_20 -> V_37 , V_43 ) ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
if ( V_20 -> V_27 )
F_15 ( V_20 ) ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
}
static int F_61 ( struct V_46 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
int V_88 = 0 ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
if ( V_20 -> V_27 )
V_88 = F_7 ( & V_20 -> V_22 ) ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
F_20 ( L_18 ,
V_20 -> V_37 , V_43 , V_88 ) ;
return V_88 ;
}
static int F_62 ( struct V_46 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
int V_89 = 0 ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
V_89 = F_6 ( & V_20 -> V_22 ) ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
F_20 ( L_19 ,
V_20 -> V_37 , V_43 , V_89 ) ;
return V_89 ;
}
static void F_63 ( struct V_46 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
unsigned long V_54 ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
if ( V_20 -> V_27 ) {
F_36 ( & V_20 -> V_59 ) ;
F_20 ( L_20 , V_20 -> V_37 ) ;
}
F_57 ( & V_20 -> V_39 , V_54 ) ;
}
static int F_64 ( struct V_46 * V_43 , int V_90 )
{
struct V_19 * V_20 = V_43 -> V_60 ;
int V_28 = 0 ;
struct V_79 * V_80 ;
F_20 ( L_21 ,
V_20 -> V_37 , V_90 ) ;
F_29 ( & V_20 -> V_39 ) ;
V_80 = V_20 -> V_27 ;
if ( V_80 && V_80 -> V_91 )
V_28 = V_80 -> V_91 ( V_80 , V_90 ) ;
F_37 ( & V_20 -> V_39 ) ;
return V_28 ;
}
static int
F_65 ( unsigned V_37 , struct V_92 * V_93 )
{
struct V_19 * V_20 ;
int V_94 = 0 ;
F_47 ( & V_71 [ V_37 ] . V_72 ) ;
if ( V_71 [ V_37 ] . V_20 ) {
V_94 = - V_75 ;
goto V_45;
}
V_20 = F_66 ( sizeof( struct V_19 ) , V_5 ) ;
if ( V_20 == NULL ) {
V_94 = - V_6 ;
goto V_45;
}
F_67 ( & V_20 -> V_20 ) ;
F_68 ( & V_20 -> V_39 ) ;
F_69 ( & V_20 -> V_35 ) ;
F_70 ( & V_20 -> V_59 , F_28 , ( unsigned long ) V_20 ) ;
F_71 ( & V_20 -> V_44 ) ;
F_71 ( & V_20 -> V_50 ) ;
F_71 ( & V_20 -> V_25 ) ;
V_20 -> V_37 = V_37 ;
V_20 -> V_95 = * V_93 ;
V_71 [ V_37 ] . V_20 = V_20 ;
V_45:
F_48 ( & V_71 [ V_37 ] . V_72 ) ;
return V_94 ;
}
static int F_72 ( struct V_19 * V_20 )
{
int V_83 ;
F_29 ( & V_20 -> V_39 ) ;
V_83 = ( V_20 -> V_20 . V_11 == 0 ) && ! V_20 -> V_74 ;
F_37 ( & V_20 -> V_39 ) ;
return V_83 ;
}
static void F_73 ( struct V_19 * V_20 )
{
F_74 ( & V_20 -> V_59 ) ;
F_75 ( V_20 -> V_20 . V_86 , F_72 ( V_20 ) ) ;
F_52 ( V_20 -> V_27 != NULL ) ;
F_76 ( & V_20 -> V_20 ) ;
F_4 ( V_20 ) ;
}
void F_77 ( unsigned char V_37 )
{
struct V_19 * V_20 ;
F_47 ( & V_71 [ V_37 ] . V_72 ) ;
if ( F_52 ( ! V_71 [ V_37 ] . V_20 ) ) {
F_48 ( & V_71 [ V_37 ] . V_72 ) ;
return;
}
V_20 = V_71 [ V_37 ] . V_20 ;
V_71 [ V_37 ] . V_20 = NULL ;
F_48 ( & V_71 [ V_37 ] . V_72 ) ;
F_73 ( V_20 ) ;
F_78 ( V_96 , V_37 ) ;
}
int F_79 ( unsigned char * V_97 )
{
struct V_92 V_93 ;
struct V_98 * V_99 ;
int V_94 ;
int V_37 ;
V_93 . V_100 = F_80 ( 9600 ) ;
V_93 . V_101 = 8 ;
V_93 . V_102 = V_103 ;
V_93 . V_104 = V_105 ;
for ( V_37 = 0 ; V_37 < V_106 ; V_37 ++ ) {
V_94 = F_65 ( V_37 , & V_93 ) ;
if ( V_94 == - V_75 )
continue;
if ( V_94 )
return V_94 ;
break;
}
if ( V_94 )
return V_94 ;
V_99 = F_81 ( & V_71 [ V_37 ] . V_20 -> V_20 ,
V_96 , V_37 , NULL ) ;
if ( F_82 ( V_99 ) ) {
struct V_19 * V_20 ;
F_83 ( L_22 ,
V_41 , V_37 , F_84 ( V_99 ) ) ;
V_94 = F_84 ( V_99 ) ;
V_20 = V_71 [ V_37 ] . V_20 ;
V_71 [ V_37 ] . V_20 = NULL ;
F_73 ( V_20 ) ;
goto V_107;
}
* V_97 = V_37 ;
V_107:
return V_94 ;
}
int F_85 ( struct V_79 * V_80 , V_38 V_37 )
{
struct V_19 * V_20 ;
unsigned long V_54 ;
int V_28 ;
if ( V_37 >= V_106 )
return - V_108 ;
V_20 = V_71 [ V_37 ] . V_20 ;
if ( ! V_20 ) {
F_83 ( L_23 , V_37 ) ;
return - V_109 ;
}
if ( V_20 -> V_27 ) {
F_83 ( L_24 , V_37 ) ;
return - V_75 ;
}
V_28 = F_86 ( V_80 -> V_26 ) ;
if ( V_28 < 0 )
return V_28 ;
V_80 -> V_26 -> V_60 = V_20 ;
V_28 = F_86 ( V_80 -> V_45 ) ;
if ( V_28 < 0 )
goto V_110;
V_80 -> V_45 -> V_60 = V_20 ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
V_80 -> V_111 = V_20 ;
V_20 -> V_27 = V_80 ;
V_80 -> V_95 = V_20 -> V_95 ;
if ( V_20 -> V_20 . V_11 ) {
F_24 ( L_25 , V_20 -> V_37 ) ;
F_45 ( V_20 ) ;
if ( V_80 -> V_81 )
V_80 -> V_81 ( V_80 ) ;
} else {
if ( V_80 -> V_51 )
V_80 -> V_51 ( V_80 ) ;
}
F_57 ( & V_20 -> V_39 , V_54 ) ;
return V_28 ;
V_110:
F_87 ( V_80 -> V_26 ) ;
V_80 -> V_26 -> V_60 = NULL ;
return V_28 ;
}
void F_88 ( struct V_79 * V_80 )
{
struct V_19 * V_20 = V_80 -> V_111 ;
unsigned long V_54 ;
if ( ! V_20 )
return;
F_56 ( & V_20 -> V_39 , V_54 ) ;
V_20 -> V_95 = V_80 -> V_95 ;
V_20 -> V_27 = NULL ;
V_80 -> V_111 = NULL ;
if ( V_20 -> V_20 . V_11 > 0 || V_20 -> V_74 ) {
F_18 ( & V_20 -> V_35 ) ;
if ( V_20 -> V_20 . V_43 )
F_89 ( V_20 -> V_20 . V_43 ) ;
}
F_57 ( & V_20 -> V_39 , V_54 ) ;
F_87 ( V_80 -> V_45 ) ;
V_80 -> V_45 -> V_60 = NULL ;
F_87 ( V_80 -> V_26 ) ;
V_80 -> V_26 -> V_60 = NULL ;
F_56 ( & V_20 -> V_39 , V_54 ) ;
if ( V_20 -> V_20 . V_11 == 0 && ! V_20 -> V_74 )
F_3 ( & V_20 -> V_22 ) ;
F_42 ( V_80 -> V_45 , & V_20 -> V_44 , NULL ) ;
F_42 ( V_80 -> V_45 , & V_20 -> V_50 , NULL ) ;
F_42 ( V_80 -> V_26 , & V_20 -> V_25 , NULL ) ;
V_20 -> V_66 = V_20 -> V_47 =
V_20 -> V_67 = V_20 -> V_30 = 0 ;
F_57 ( & V_20 -> V_39 , V_54 ) ;
}
static int F_90 ( void )
{
unsigned V_63 ;
int V_28 ;
V_96 = F_91 ( V_106 ) ;
if ( ! V_96 )
return - V_6 ;
V_96 -> V_112 = L_26 ;
V_96 -> V_42 = L_27 ;
V_96 -> type = V_113 ;
V_96 -> V_114 = V_115 ;
V_96 -> V_54 = V_116 | V_117 ;
V_96 -> V_118 = V_119 ;
V_96 -> V_118 . V_120 =
V_121 | V_122 | V_123 | V_124 | V_125 ;
V_96 -> V_118 . V_126 = 9600 ;
V_96 -> V_118 . V_127 = 9600 ;
F_92 ( V_96 , & V_128 ) ;
for ( V_63 = 0 ; V_63 < V_106 ; V_63 ++ )
F_93 ( & V_71 [ V_63 ] . V_72 ) ;
V_28 = F_94 ( V_96 ) ;
if ( V_28 ) {
F_83 ( L_28 ,
V_41 , V_28 ) ;
goto V_129;
}
F_24 ( L_29 , V_41 ,
V_106 ,
( V_106 == 1 ) ? L_30 : L_31 ) ;
return V_28 ;
V_129:
F_95 ( V_96 ) ;
V_96 = NULL ;
return V_28 ;
}
static void F_96 ( void )
{
F_97 ( V_96 ) ;
F_95 ( V_96 ) ;
V_96 = NULL ;
}

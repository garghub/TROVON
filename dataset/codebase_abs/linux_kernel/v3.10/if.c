const char * F_1 ( int V_1 )
{
return ( V_1 <= 6 ) ? V_2 [ V_1 ] : L_1 ;
}
static int
F_2 ( unsigned long V_3 , unsigned long V_4 ,
unsigned int type , bool V_5 , struct V_6 * V_6 , int V_7 )
{
unsigned int * V_8 = F_3 ( V_6 ) ;
int V_9 , V_10 ;
V_10 = V_11 ;
if ( V_8 == NULL ) {
V_8 = F_4 ( V_10 * sizeof *V_8 , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
F_3 ( V_6 ) = V_8 ;
}
if ( ! V_7 ) {
if ( ( V_3 & ( V_14 - 1 ) ) || ( V_4 & ( V_14 - 1 ) ) )
return - V_15 ;
V_3 >>= V_16 ;
V_4 >>= V_16 ;
}
V_9 = F_5 ( V_3 , V_4 , type , true ) ;
if ( V_9 >= 0 )
++ V_8 [ V_9 ] ;
return V_9 ;
}
static int
F_6 ( unsigned long V_3 , unsigned long V_4 ,
struct V_6 * V_6 , int V_7 )
{
unsigned int * V_8 = F_3 ( V_6 ) ;
int V_9 ;
if ( ! V_7 ) {
if ( ( V_3 & ( V_14 - 1 ) ) || ( V_4 & ( V_14 - 1 ) ) )
return - V_15 ;
V_3 >>= V_16 ;
V_4 >>= V_16 ;
}
V_9 = F_7 ( - 1 , V_3 , V_4 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_8 == NULL )
return V_9 ;
if ( V_8 [ V_9 ] < 1 )
return - V_15 ;
-- V_8 [ V_9 ] ;
return V_9 ;
}
static T_1
F_8 ( struct V_6 * V_6 , const char T_2 * V_17 , T_3 V_18 , T_4 * V_19 )
{
int V_20 , V_21 ;
unsigned long V_9 ;
unsigned long long V_3 , V_4 ;
char * V_22 ;
char line [ V_23 ] ;
int V_24 ;
T_3 V_25 ;
if ( ! F_9 ( V_26 ) )
return - V_27 ;
memset ( line , 0 , V_23 ) ;
V_24 = V_18 ;
V_24 -- ;
if ( V_24 > V_23 - 1 )
V_24 = V_23 - 1 ;
if ( V_24 < 0 )
return - V_15 ;
if ( F_10 ( line , V_17 , V_24 ) )
return - V_28 ;
V_25 = strlen ( line ) ;
V_22 = line + V_25 - 1 ;
if ( V_25 && * V_22 == '\n' )
* V_22 = '\0' ;
if ( ! strncmp ( line , L_2 , 8 ) ) {
V_9 = F_11 ( line + 8 , & V_22 , 0 ) ;
V_21 = F_7 ( V_9 , 0 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_18 ;
}
if ( strncmp ( line , L_3 , 5 ) )
return - V_15 ;
V_3 = F_12 ( line + 5 , & V_22 , 0 ) ;
V_22 = F_13 ( V_22 ) ;
if ( strncmp ( V_22 , L_4 , 5 ) )
return - V_15 ;
V_4 = F_12 ( V_22 + 5 , & V_22 , 0 ) ;
if ( ( V_3 & 0xfff ) || ( V_4 & 0xfff ) )
return - V_15 ;
V_22 = F_13 ( V_22 ) ;
if ( strncmp ( V_22 , L_5 , 5 ) )
return - V_15 ;
V_22 = F_13 ( V_22 + 5 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; ++ V_20 ) {
if ( strcmp ( V_22 , V_2 [ V_20 ] ) )
continue;
V_3 >>= V_16 ;
V_4 >>= V_16 ;
V_21 = F_5 ( ( unsigned long ) V_3 , ( unsigned long ) V_4 , V_20 , true ) ;
if ( V_21 < 0 )
return V_21 ;
return V_18 ;
}
return - V_15 ;
}
static long
F_14 ( struct V_6 * V_6 , unsigned int V_30 , unsigned long V_31 )
{
int V_21 = 0 ;
T_5 type ;
unsigned long V_3 ;
unsigned long V_4 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
void T_2 * V_36 = ( void T_2 * ) V_31 ;
switch ( V_30 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
if ( F_10 ( & V_33 , V_36 , sizeof V_33 ) )
return - V_28 ;
break;
case V_45 :
case V_46 :
if ( F_10 ( & V_35 , V_36 , sizeof V_35 ) )
return - V_28 ;
break;
#ifdef F_15
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 : {
struct V_55 T_2 * V_56 ;
V_56 = (struct V_55 T_2 * ) V_31 ;
V_21 = F_16 ( V_33 . V_3 , & V_56 -> V_3 ) ;
V_21 |= F_16 ( V_33 . V_4 , & V_56 -> V_4 ) ;
V_21 |= F_16 ( V_33 . type , & V_56 -> type ) ;
if ( V_21 )
return V_21 ;
break;
}
case V_57 :
case V_58 : {
struct V_59 T_2 * V_60 ;
V_60 = (struct V_59 T_2 * ) V_31 ;
V_21 = F_16 ( V_35 . V_61 , & V_60 -> V_61 ) ;
V_21 |= F_16 ( V_35 . V_3 , & V_60 -> V_3 ) ;
V_21 |= F_16 ( V_35 . V_4 , & V_60 -> V_4 ) ;
V_21 |= F_16 ( V_35 . type , & V_60 -> type ) ;
if ( V_21 )
return V_21 ;
break;
}
#endif
}
switch ( V_30 ) {
default:
return - V_62 ;
case V_37 :
#ifdef F_15
case V_47 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 =
F_2 ( V_33 . V_3 , V_33 . V_4 , V_33 . type , true ,
V_6 , 0 ) ;
break;
case V_38 :
#ifdef F_15
case V_48 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 = F_17 ( V_33 . V_3 , V_33 . V_4 , V_33 . type , false ) ;
break;
case V_39 :
#ifdef F_15
case V_49 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 = F_6 ( V_33 . V_3 , V_33 . V_4 , V_6 , 0 ) ;
break;
case V_40 :
#ifdef F_15
case V_50 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 = F_18 ( - 1 , V_33 . V_3 , V_33 . V_4 ) ;
break;
case V_45 :
#ifdef F_15
case V_57 :
#endif
if ( V_35 . V_61 >= V_11 )
return - V_15 ;
V_63 -> V_64 ( V_35 . V_61 , & V_3 , & V_4 , & type ) ;
if ( V_3 + V_4 - 1 >= ( 1UL << ( 8 * sizeof( V_35 . V_4 ) - V_16 ) )
|| V_4 >= ( 1UL << ( 8 * sizeof( V_35 . V_4 ) - V_16 ) ) )
V_35 . V_3 = V_35 . V_4 = V_35 . type = 0 ;
else {
V_35 . V_3 = V_3 << V_16 ;
V_35 . V_4 = V_4 << V_16 ;
V_35 . type = type ;
}
break;
case V_41 :
#ifdef F_15
case V_51 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 =
F_2 ( V_33 . V_3 , V_33 . V_4 , V_33 . type , true ,
V_6 , 1 ) ;
break;
case V_42 :
#ifdef F_15
case V_52 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 =
F_5 ( V_33 . V_3 , V_33 . V_4 , V_33 . type , false ) ;
break;
case V_43 :
#ifdef F_15
case V_53 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 = F_6 ( V_33 . V_3 , V_33 . V_4 , V_6 , 1 ) ;
break;
case V_44 :
#ifdef F_15
case V_54 :
#endif
if ( ! F_9 ( V_26 ) )
return - V_27 ;
V_21 = F_7 ( - 1 , V_33 . V_3 , V_33 . V_4 ) ;
break;
case V_46 :
#ifdef F_15
case V_58 :
#endif
if ( V_35 . V_61 >= V_11 )
return - V_15 ;
V_63 -> V_64 ( V_35 . V_61 , & V_3 , & V_4 , & type ) ;
if ( V_4 != ( F_19 ( V_35 . V_4 ) ) V_4 )
V_35 . V_3 = V_35 . V_4 = V_35 . type = 0 ;
else {
V_35 . V_3 = V_3 ;
V_35 . V_4 = V_4 ;
V_35 . type = type ;
}
break;
}
if ( V_21 )
return V_21 ;
switch ( V_30 ) {
case V_45 :
case V_46 :
if ( F_20 ( V_36 , & V_35 , sizeof V_35 ) )
V_21 = - V_28 ;
break;
#ifdef F_15
case V_57 :
case V_58 : {
struct V_59 T_2 * V_60 ;
V_60 = (struct V_59 T_2 * ) V_31 ;
V_21 = F_21 ( V_35 . V_3 , & V_60 -> V_3 ) ;
V_21 |= F_21 ( V_35 . V_4 , & V_60 -> V_4 ) ;
V_21 |= F_21 ( V_35 . V_61 , & V_60 -> V_61 ) ;
V_21 |= F_21 ( V_35 . type , & V_60 -> type ) ;
break;
}
#endif
}
return V_21 ;
}
static int F_22 ( struct V_65 * V_66 , struct V_6 * V_6 )
{
unsigned int * V_8 = F_3 ( V_6 ) ;
int V_20 , V_10 ;
if ( V_8 != NULL ) {
V_10 = V_11 ;
for ( V_20 = 0 ; V_20 < V_10 ; ++ V_20 ) {
while ( V_8 [ V_20 ] > 0 ) {
F_18 ( V_20 , 0 , 0 ) ;
-- V_8 [ V_20 ] ;
}
}
F_23 ( V_8 ) ;
F_3 ( V_6 ) = NULL ;
}
return F_24 ( V_66 , V_6 ) ;
}
static int F_25 ( struct V_65 * V_65 , struct V_6 * V_6 )
{
if ( ! V_63 )
return - V_67 ;
if ( ! V_63 -> V_64 )
return - V_68 ;
return F_26 ( V_6 , V_69 , NULL ) ;
}
static int V_69 ( struct V_70 * V_71 , void * V_72 )
{
char V_73 ;
int V_20 , V_10 , V_18 ;
T_5 type ;
unsigned long V_3 , V_4 ;
V_18 = 0 ;
V_10 = V_11 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
V_63 -> V_64 ( V_20 , & V_3 , & V_4 , & type ) ;
if ( V_4 == 0 ) {
V_74 [ V_20 ] = 0 ;
continue;
}
if ( V_4 < ( 0x100000 >> V_16 ) ) {
V_73 = 'K' ;
V_4 <<= V_16 - 10 ;
} else {
V_73 = 'M' ;
V_4 >>= 20 - V_16 ;
}
V_18 += F_27 ( V_71 , L_6
L_7 ,
V_20 , V_3 , V_3 >> ( 20 - V_16 ) , V_4 ,
V_73 , V_74 [ V_20 ] ,
F_1 ( type ) ) ;
}
return 0 ;
}
static int T_6 F_28 ( void )
{
struct V_75 * V_76 = & V_77 ;
if ( ( ! F_29 ( V_76 , V_78 ) ) &&
( ! F_29 ( V_76 , V_79 ) ) &&
( ! F_29 ( V_76 , V_80 ) ) &&
( ! F_29 ( V_76 , V_81 ) ) )
return - V_82 ;
F_30 ( L_8 , V_83 | V_84 , NULL , & V_85 ) ;
return 0 ;
}

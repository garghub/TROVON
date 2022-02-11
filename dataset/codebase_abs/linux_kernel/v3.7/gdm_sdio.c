static void F_1 ( char * V_1 , T_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_5 L_1 , V_1 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_5 L_2 , V_2 [ V_4 ] ) ;
if ( ( V_4 & 0xf ) == 0xf )
F_2 ( V_5 L_3 ) ;
}
F_2 ( V_5 L_3 ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_4 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = F_5 ( V_12 , V_10 ) ;
if ( ! V_9 -> V_11 ) {
F_6 ( V_9 ) ;
return NULL ;
}
V_9 -> V_7 = V_8 ;
return V_9 ;
}
static void F_7 ( struct V_6 * V_9 )
{
if ( V_9 ) {
F_6 ( V_9 -> V_11 ) ;
F_6 ( V_9 ) ;
}
}
static struct V_13 * F_8 ( struct V_14 * V_15 )
{
struct V_13 * V_16 = F_4 ( sizeof( * V_16 ) , V_10 ) ;
if ( V_16 )
V_16 -> V_14 = V_15 ;
return V_16 ;
}
static void F_9 ( struct V_13 * V_16 )
{
F_6 ( V_16 ) ;
}
static struct V_6 * F_10 ( struct V_7 * V_8 , int * V_17 )
{
struct V_6 * V_9 ;
if ( F_11 ( & V_8 -> V_18 ) )
return NULL ;
V_9 = F_12 ( V_8 -> V_18 . V_19 , struct V_6 , V_20 ) ;
F_13 ( & V_9 -> V_20 ) ;
* V_17 = F_11 ( & V_8 -> V_18 ) ? 1 : 0 ;
return V_9 ;
}
static void F_14 ( struct V_7 * V_8 , struct V_6 * V_9 )
{
F_15 ( & V_9 -> V_20 , & V_8 -> V_18 ) ;
}
static struct V_13 * F_16 ( struct V_14 * V_15 )
{
struct V_13 * V_16 ;
if ( F_11 ( & V_15 -> V_18 ) )
return NULL ;
V_16 = F_12 ( V_15 -> V_18 . V_19 , struct V_13 , V_20 ) ;
F_13 ( & V_16 -> V_20 ) ;
return V_16 ;
}
static void F_17 ( struct V_14 * V_15 , struct V_13 * V_16 )
{
F_15 ( & V_16 -> V_20 , & V_15 -> V_18 ) ;
}
static int F_18 ( struct V_21 * V_22 )
{
int V_23 = 0 , V_4 ;
struct V_7 * V_8 = & V_22 -> V_8 ;
struct V_14 * V_15 = & V_22 -> V_15 ;
struct V_6 * V_9 ;
struct V_13 * V_16 ;
F_19 ( & V_8 -> V_18 ) ;
F_19 ( & V_8 -> V_24 ) ;
F_19 ( & V_8 -> V_25 ) ;
F_20 ( & V_8 -> V_26 ) ;
V_8 -> V_27 = F_5 ( V_28 , V_29 ) ;
if ( V_8 -> V_27 == NULL ) {
F_2 ( V_30 L_4 ) ;
goto V_31;
}
for ( V_4 = 0 ; V_4 < V_32 ; V_4 ++ ) {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
V_23 = - V_33 ;
goto V_31;
}
F_21 ( & V_9 -> V_20 , & V_8 -> V_18 ) ;
}
F_19 ( & V_15 -> V_18 ) ;
F_19 ( & V_15 -> V_34 ) ;
F_20 ( & V_15 -> V_26 ) ;
for ( V_4 = 0 ; V_4 < V_35 ; V_4 ++ ) {
V_16 = F_8 ( V_15 ) ;
if ( V_16 == NULL ) {
V_23 = - V_33 ;
goto V_31;
}
F_21 ( & V_16 -> V_20 , & V_15 -> V_18 ) ;
}
V_15 -> V_36 = F_5 ( V_37 , V_29 ) ;
if ( V_15 -> V_36 == NULL ) {
F_2 ( V_30 L_5 ) ;
goto V_31;
}
return 0 ;
V_31:
F_22 ( V_22 ) ;
return V_23 ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_7 * V_8 = & V_22 -> V_8 ;
struct V_14 * V_15 = & V_22 -> V_15 ;
struct V_6 * V_9 , * V_38 ;
struct V_13 * V_16 , * V_39 ;
F_6 ( V_8 -> V_27 ) ;
F_23 (t, t_next, &tx->free_list, list) {
F_13 ( & V_9 -> V_20 ) ;
F_7 ( V_9 ) ;
}
F_23 (t, t_next, &tx->sdu_list, list) {
F_13 ( & V_9 -> V_20 ) ;
F_7 ( V_9 ) ;
}
F_23 (t, t_next, &tx->hci_list, list) {
F_13 ( & V_9 -> V_20 ) ;
F_7 ( V_9 ) ;
}
F_6 ( V_15 -> V_36 ) ;
F_23 (r, r_next, &rx->free_list, list) {
F_13 ( & V_16 -> V_20 ) ;
F_9 ( V_16 ) ;
}
F_23 (r, r_next, &rx->req_list, list) {
F_13 ( & V_16 -> V_20 ) ;
F_9 ( V_16 ) ;
}
}
static void F_24 ( struct V_40 * V_41 , T_1 * V_2 , int V_3 )
{
int V_42 , V_43 , V_23 , V_44 ;
F_25 ( V_41 ) ;
V_43 = V_3 / V_41 -> V_45 ;
V_42 = V_43 * V_41 -> V_45 ;
if ( V_43 ) {
V_23 = F_26 ( V_41 , 0 , V_2 , V_42 ) ;
if ( V_23 < 0 ) {
if ( V_23 != - V_46 )
F_2 ( V_30 L_6 ,
V_47 , V_23 ) ;
goto V_48;
}
}
V_44 = V_3 - V_42 ;
V_44 = ( V_44 + 3 ) & ~ 3 ;
if ( V_44 ) {
V_23 = F_26 ( V_41 , 0 , V_2 + V_42 , V_44 ) ;
if ( V_23 < 0 ) {
if ( V_23 != - V_46 )
F_2 ( V_30 L_6 ,
V_47 , V_23 ) ;
goto V_48;
}
}
V_48:
F_27 ( V_41 ) ;
}
static void F_28 ( struct V_40 * V_41 , struct V_7 * V_8 )
{
struct V_49 * V_50 , * V_51 ;
struct V_52 * V_53 ;
struct V_6 * V_9 ;
int V_54 , V_3 , V_4 , V_55 , V_56 = 0 , V_57 ;
T_1 * V_11 ;
unsigned long V_58 ;
F_29 ( & V_8 -> V_26 , V_58 ) ;
V_54 = V_59 + V_60 ;
F_30 (t, &tx->sdu_list, list) {
V_55 = ( ( V_9 -> V_3 + 3 ) & ~ 3 ) + 4 ;
if ( ( V_54 + V_55 ) > V_28 )
break;
V_56 ++ ;
memcpy ( V_8 -> V_27 + V_54 , V_9 -> V_11 , V_9 -> V_3 ) ;
memset ( V_8 -> V_27 + V_54 + V_9 -> V_3 , 0 , V_55 - V_9 -> V_3 ) ;
V_54 += V_55 ;
}
V_57 = V_54 ;
V_53 = (struct V_52 * ) ( V_8 -> V_27 + V_59 ) ;
V_53 -> V_61 = F_31 ( V_62 ) ;
V_53 -> V_63 = F_31 ( V_57 - V_59 - V_60 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
#ifdef F_33
F_1 ( L_7 , V_8 -> V_27 + V_59 ,
V_57 - V_59 ) ;
#endif
for ( V_54 = V_59 ; V_54 < V_57 ; V_54 += V_64 ) {
V_3 = V_57 - V_54 ;
V_3 = V_3 > V_64 ? V_64 : V_3 ;
V_11 = V_8 -> V_27 + V_54 - V_59 ;
V_11 [ 0 ] = V_3 & 0xff ;
V_11 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_11 [ 2 ] = ( V_3 >> 16 ) & 0xff ;
V_11 [ 3 ] = ( V_54 + V_3 ) >= V_57 ? 0 : 1 ;
F_24 ( V_41 , V_11 , V_3 + V_59 ) ;
}
F_29 ( & V_8 -> V_26 , V_58 ) ;
for ( V_50 = V_8 -> V_24 . V_51 , V_4 = 0 ; V_4 < V_56 ; V_4 ++ , V_50 = V_51 ) {
V_51 = V_50 -> V_51 ;
V_9 = F_12 ( V_50 , struct V_6 , V_20 ) ;
if ( V_9 -> V_65 )
V_9 -> V_65 ( V_9 -> V_66 ) ;
F_13 ( V_50 ) ;
F_14 ( V_9 -> V_7 , V_9 ) ;
}
F_34 ( & V_8 -> V_67 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
}
static void F_35 ( struct V_40 * V_41 , struct V_7 * V_8 ,
struct V_6 * V_9 )
{
unsigned long V_58 ;
#ifdef F_33
F_1 ( L_7 , V_9 -> V_11 + V_59 ,
V_9 -> V_3 - V_59 ) ;
#endif
F_24 ( V_41 , V_9 -> V_11 , V_9 -> V_3 ) ;
F_29 ( & V_8 -> V_26 , V_58 ) ;
if ( V_9 -> V_65 )
V_9 -> V_65 ( V_9 -> V_66 ) ;
F_7 ( V_9 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
}
static void F_36 ( struct V_68 * V_69 )
{
struct V_21 * V_22 = F_37 ( V_69 , struct V_21 , V_70 ) ;
struct V_40 * V_41 = V_22 -> V_41 ;
struct V_7 * V_8 = & V_22 -> V_8 ;
struct V_6 * V_9 = NULL ;
struct V_71 V_72 , * V_73 ;
int V_74 = 0 ;
long V_75 ;
unsigned long V_58 ;
F_29 ( & V_8 -> V_26 , V_58 ) ;
if ( ! V_8 -> V_76 ) {
F_32 ( & V_8 -> V_26 , V_58 ) ;
return;
}
if ( ! F_11 ( & V_8 -> V_25 ) ) {
V_9 = F_12 ( V_8 -> V_25 . V_51 , struct V_6 , V_20 ) ;
F_13 ( & V_9 -> V_20 ) ;
V_74 = 0 ;
} else if ( ! V_8 -> V_77 && ! F_11 ( & V_8 -> V_24 ) ) {
F_34 ( & V_72 ) ;
V_73 = & V_8 -> V_67 ;
V_75 = ( V_72 . V_78 - V_73 -> V_78 ) * 1000000 +
( V_72 . V_79 - V_73 -> V_79 ) ;
if ( V_75 >= 0 && V_75 < V_80 ) {
F_38 ( & V_22 -> V_70 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
return;
}
V_74 = 1 ;
}
if ( ! V_74 && V_9 == NULL ) {
F_32 ( & V_8 -> V_26 , V_58 ) ;
return;
}
V_8 -> V_76 = 0 ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
if ( V_74 )
F_28 ( V_41 , V_8 ) ;
else
F_35 ( V_41 , V_8 , V_9 ) ;
}
static int F_39 ( void * V_81 , void * V_2 , int V_3 ,
void (* F_40)( void * V_2 ) , void * V_66 )
{
struct V_21 * V_22 = V_81 ;
struct V_7 * V_8 = & V_22 -> V_8 ;
struct V_6 * V_9 ;
T_1 * V_82 = V_2 ;
int V_17 = 0 ;
T_2 V_61 ;
unsigned long V_58 ;
F_41 ( V_3 > V_12 - V_59 ) ;
F_29 ( & V_8 -> V_26 , V_58 ) ;
V_61 = ( V_82 [ 0 ] << 8 ) | V_82 [ 1 ] ;
if ( V_61 == V_83 ) {
V_9 = F_10 ( V_8 , & V_17 ) ;
if ( V_9 == NULL ) {
F_32 ( & V_8 -> V_26 , V_58 ) ;
return - V_84 ;
}
F_15 ( & V_9 -> V_20 , & V_8 -> V_24 ) ;
memcpy ( V_9 -> V_11 , V_2 , V_3 ) ;
V_9 -> V_3 = V_3 ;
V_9 -> V_65 = F_40 ;
V_9 -> V_66 = V_66 ;
} else {
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL ) {
F_32 ( & V_8 -> V_26 , V_58 ) ;
return - V_33 ;
}
F_15 ( & V_9 -> V_20 , & V_8 -> V_25 ) ;
V_9 -> V_11 [ 0 ] = V_3 & 0xff ;
V_9 -> V_11 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_9 -> V_11 [ 2 ] = ( V_3 >> 16 ) & 0xff ;
V_9 -> V_11 [ 3 ] = 2 ;
memcpy ( V_9 -> V_11 + V_59 , V_2 , V_3 ) ;
V_9 -> V_3 = V_3 + V_59 ;
V_9 -> V_65 = F_40 ;
V_9 -> V_66 = V_66 ;
}
if ( V_8 -> V_76 )
F_38 ( & V_22 -> V_70 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
if ( V_17 )
return - V_84 ;
return 0 ;
}
static int F_42 ( struct V_21 * V_22 , T_1 * V_85 , int V_3 )
{
struct V_7 * V_8 = & V_22 -> V_8 ;
T_2 V_61 ;
unsigned long V_58 ;
F_29 ( & V_8 -> V_26 , V_58 ) ;
V_61 = ( V_85 [ 0 ] << 8 ) | ( V_85 [ 1 ] ) ;
if ( V_61 != V_86 )
goto V_87;
if ( V_85 [ 4 ] == 0 ) {
#ifdef F_33
F_2 ( V_5 L_8 ) ;
#endif
V_8 -> V_77 = 1 ;
} else if ( V_85 [ 4 ] == 1 ) {
#ifdef F_33
F_2 ( V_5 L_9 ) ;
#endif
V_8 -> V_77 = 0 ;
if ( V_8 -> V_76 )
F_38 ( & V_22 -> V_70 ) ;
if ( F_11 ( & V_8 -> V_18 ) )
V_3 = 0 ;
}
V_87:
F_32 ( & V_8 -> V_26 , V_58 ) ;
return V_3 ;
}
static void F_43 ( struct V_40 * V_41 )
{
struct V_88 * V_88 = F_44 ( V_41 ) ;
struct V_21 * V_22 = V_88 -> V_81 ;
struct V_7 * V_8 = & V_22 -> V_8 ;
struct V_14 * V_15 = & V_22 -> V_15 ;
struct V_13 * V_16 ;
unsigned long V_58 ;
T_1 V_89 , V_90 [ V_91 ] , * V_11 ;
T_3 V_3 , V_43 , V_42 ;
int V_23 , V_44 ;
V_89 = F_45 ( V_41 , 0x13 , & V_23 ) ;
if ( V_89 & 0x01 )
F_46 ( V_41 , 0x01 , 0x13 , & V_23 ) ;
else
return;
V_23 = F_47 ( V_41 , V_90 , 0x0 , V_91 ) ;
if ( V_23 ) {
F_2 ( V_30 L_10 , V_41 -> V_92 ) ;
goto V_93;
}
V_3 = ( V_90 [ 2 ] << 16 ) | ( V_90 [ 1 ] << 8 ) | V_90 [ 0 ] ;
if ( V_3 > ( V_37 - V_59 ) ) {
F_2 ( V_30 L_11 , V_3 ) ;
goto V_93;
}
if ( V_90 [ 3 ] == 1 ) {
#ifdef F_33
T_3 * V_94 = ( T_3 * ) & V_90 [ 4 ] ;
#endif
F_29 ( & V_8 -> V_26 , V_58 ) ;
V_8 -> V_76 = 1 ;
if ( ! F_11 ( & V_8 -> V_24 ) || ! F_11 ( & V_8 -> V_25 ) )
F_38 ( & V_22 -> V_70 ) ;
F_32 ( & V_8 -> V_26 , V_58 ) ;
#ifdef F_33
F_2 ( V_5 L_12 , F_48 ( * V_94 ) ) ;
#endif
goto V_93;
}
memcpy ( V_15 -> V_36 , V_90 + V_59 ,
V_91 - V_59 ) ;
V_11 = V_15 -> V_36 + V_91 - V_59 ;
V_44 = V_3 - V_91 + V_59 ;
if ( V_44 <= 0 )
goto V_48;
V_43 = V_44 / V_41 -> V_45 ;
if ( V_43 ) {
V_42 = V_43 * V_41 -> V_45 ;
V_23 = F_47 ( V_41 , V_11 , 0x0 , V_42 ) ;
if ( V_23 ) {
F_2 ( V_30 L_10 ,
V_41 -> V_92 ) ;
goto V_93;
}
V_11 += V_42 ;
V_44 -= V_42 ;
}
if ( V_44 ) {
V_23 = F_47 ( V_41 , V_11 , 0x0 , V_44 ) ;
if ( V_23 ) {
F_2 ( V_30 L_10 ,
V_41 -> V_92 ) ;
goto V_93;
}
}
V_48:
#ifdef F_33
F_1 ( L_13 , V_15 -> V_36 , V_3 ) ;
#endif
V_3 = F_42 ( V_22 , V_15 -> V_36 , V_3 ) ;
F_29 ( & V_15 -> V_26 , V_58 ) ;
if ( ! F_11 ( & V_15 -> V_34 ) ) {
V_16 = F_12 ( V_15 -> V_34 . V_51 , struct V_13 , V_20 ) ;
F_32 ( & V_15 -> V_26 , V_58 ) ;
if ( V_16 -> V_65 )
V_16 -> V_65 ( V_16 -> V_66 , V_15 -> V_36 , V_3 ) ;
F_29 ( & V_15 -> V_26 , V_58 ) ;
F_13 ( & V_16 -> V_20 ) ;
F_17 ( V_15 , V_16 ) ;
}
F_32 ( & V_15 -> V_26 , V_58 ) ;
V_93:
F_46 ( V_41 , 0x00 , 0x10 , & V_23 ) ;
if ( ! V_88 -> V_95 )
F_49 ( V_88 , & V_41 -> V_96 ) ;
}
static int F_50 ( void * V_81 ,
void (* F_40)( void * V_66 , void * V_2 , int V_3 ) ,
void * V_66 )
{
struct V_21 * V_22 = V_81 ;
struct V_14 * V_15 = & V_22 -> V_15 ;
struct V_13 * V_16 ;
unsigned long V_58 ;
F_29 ( & V_15 -> V_26 , V_58 ) ;
V_16 = F_16 ( V_15 ) ;
if ( V_16 == NULL ) {
F_32 ( & V_15 -> V_26 , V_58 ) ;
return - V_33 ;
}
V_16 -> V_65 = F_40 ;
V_16 -> V_66 = V_66 ;
F_15 ( & V_16 -> V_20 , & V_15 -> V_34 ) ;
F_32 ( & V_15 -> V_26 , V_58 ) ;
return 0 ;
}
static int F_51 ( struct V_40 * V_41 ,
const struct V_97 * V_98 )
{
int V_23 ;
struct V_88 * V_88 = NULL ;
struct V_21 * V_22 = NULL ;
F_2 ( V_99 L_14 ,
V_41 -> V_100 , V_41 -> V_101 ) ;
F_2 ( V_99 L_15 , V_102 ) ;
F_25 ( V_41 ) ;
F_52 ( V_41 ) ;
F_53 ( V_41 , F_43 ) ;
V_23 = F_54 ( V_41 ) ;
if ( V_23 )
return V_23 ;
V_88 = F_4 ( sizeof( * V_88 ) , V_29 ) ;
if ( V_88 == NULL ) {
V_23 = - V_33 ;
goto V_87;
}
V_22 = F_4 ( sizeof( * V_22 ) , V_29 ) ;
if ( V_22 == NULL ) {
V_23 = - V_33 ;
goto V_87;
}
V_88 -> V_81 = ( void * ) V_22 ;
V_88 -> V_103 = F_39 ;
V_88 -> V_104 = F_50 ;
V_23 = F_18 ( V_22 ) ;
if ( V_23 < 0 )
goto V_87;
V_22 -> V_41 = V_41 ;
F_46 ( V_41 , 1 , 0x14 , & V_23 ) ;
F_27 ( V_41 ) ;
F_55 ( & V_22 -> V_70 , F_36 ) ;
F_56 ( V_41 , V_88 ) ;
V_87:
if ( V_23 ) {
F_6 ( V_88 ) ;
F_6 ( V_22 ) ;
}
return V_23 ;
}
static void F_57 ( struct V_40 * V_41 )
{
struct V_88 * V_88 = F_44 ( V_41 ) ;
struct V_21 * V_22 = V_88 -> V_81 ;
if ( V_88 -> V_95 )
F_58 ( V_88 ) ;
F_25 ( V_41 ) ;
F_59 ( V_41 ) ;
F_60 ( V_41 ) ;
F_27 ( V_41 ) ;
F_22 ( V_22 ) ;
F_6 ( V_22 ) ;
F_6 ( V_88 ) ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_105 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_105 ) ;
}

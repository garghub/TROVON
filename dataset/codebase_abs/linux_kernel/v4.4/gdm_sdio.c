static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = F_3 ( V_7 , V_5 ) ;
if ( ! V_4 -> V_6 ) {
F_4 ( V_4 ) ;
return NULL ;
}
V_4 -> V_2 = V_3 ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_4 ( V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_2 ( sizeof( * V_11 ) , V_5 ) ;
if ( V_11 )
V_11 -> V_9 = V_10 ;
return V_11 ;
}
static void F_7 ( struct V_8 * V_11 )
{
F_4 ( V_11 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 , int * V_12 )
{
struct V_1 * V_4 ;
if ( F_9 ( & V_3 -> V_13 ) )
return NULL ;
V_4 = F_10 ( V_3 -> V_13 . V_14 , struct V_1 , V_15 ) ;
F_11 ( & V_4 -> V_15 ) ;
* V_12 = F_9 ( & V_3 -> V_13 ) ? 1 : 0 ;
return V_4 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
F_13 ( & V_4 -> V_15 , & V_3 -> V_13 ) ;
}
static struct V_8 * F_14 ( struct V_9 * V_10 )
{
struct V_8 * V_11 ;
if ( F_9 ( & V_10 -> V_13 ) )
return NULL ;
V_11 = F_10 ( V_10 -> V_13 . V_14 , struct V_8 , V_15 ) ;
F_11 ( & V_11 -> V_15 ) ;
return V_11 ;
}
static void F_15 ( struct V_9 * V_10 , struct V_8 * V_11 )
{
F_13 ( & V_11 -> V_15 , & V_10 -> V_13 ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_1 * V_4 , * V_18 ;
struct V_8 * V_11 , * V_19 ;
F_4 ( V_3 -> V_20 ) ;
F_17 (t, t_next, &tx->free_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_17 (t, t_next, &tx->sdu_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_17 (t, t_next, &tx->hci_list, list) {
F_11 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
F_4 ( V_10 -> V_21 ) ;
F_17 (r, r_next, &rx->free_list, list) {
F_11 ( & V_11 -> V_15 ) ;
F_7 ( V_11 ) ;
}
F_17 (r, r_next, &rx->req_list, list) {
F_11 ( & V_11 -> V_15 ) ;
F_7 ( V_11 ) ;
}
}
static int F_18 ( struct V_16 * V_17 )
{
int V_22 = 0 , V_23 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_1 * V_4 ;
struct V_8 * V_11 ;
F_19 ( & V_3 -> V_13 ) ;
F_19 ( & V_3 -> V_24 ) ;
F_19 ( & V_3 -> V_25 ) ;
F_20 ( & V_3 -> V_26 ) ;
V_3 -> V_20 = F_3 ( V_27 , V_28 ) ;
if ( ! V_3 -> V_20 )
goto V_29;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_22 = - V_31 ;
goto V_29;
}
F_21 ( & V_4 -> V_15 , & V_3 -> V_13 ) ;
}
F_19 ( & V_10 -> V_13 ) ;
F_19 ( & V_10 -> V_32 ) ;
F_20 ( & V_10 -> V_26 ) ;
for ( V_23 = 0 ; V_23 < V_33 ; V_23 ++ ) {
V_11 = F_6 ( V_10 ) ;
if ( ! V_11 ) {
V_22 = - V_31 ;
goto V_29;
}
F_21 ( & V_11 -> V_15 , & V_10 -> V_13 ) ;
}
V_10 -> V_21 = F_3 ( V_34 , V_28 ) ;
if ( ! V_10 -> V_21 )
goto V_29;
return 0 ;
V_29:
F_16 ( V_17 ) ;
return V_22 ;
}
static void F_22 ( struct V_35 * V_36 , T_1 * V_37 , int V_38 )
{
int V_39 , V_40 , V_22 , V_41 ;
F_23 ( V_36 ) ;
V_40 = V_38 / V_36 -> V_42 ;
V_39 = V_40 * V_36 -> V_42 ;
if ( V_40 ) {
V_22 = F_24 ( V_36 , 0 , V_37 , V_39 ) ;
if ( V_22 < 0 ) {
if ( V_22 != - V_43 )
F_25 ( & V_36 -> V_44 ,
L_1 , V_22 ) ;
goto V_45;
}
}
V_41 = V_38 - V_39 ;
V_41 = ( V_41 + 3 ) & ~ 3 ;
if ( V_41 ) {
V_22 = F_24 ( V_36 , 0 , V_37 + V_39 , V_41 ) ;
if ( V_22 < 0 ) {
if ( V_22 != - V_43 )
F_25 ( & V_36 -> V_44 ,
L_1 , V_22 ) ;
goto V_45;
}
}
V_45:
F_26 ( V_36 ) ;
}
static void F_27 ( struct V_35 * V_36 , struct V_2 * V_3 )
{
struct V_46 * V_47 , * V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_4 ;
int V_51 , V_38 , V_23 , V_52 , V_53 = 0 , V_54 ;
T_1 * V_6 ;
unsigned long V_55 ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
V_51 = V_56 + V_57 ;
F_29 (t, &tx->sdu_list, list) {
V_52 = ( ( V_4 -> V_38 + 3 ) & ~ 3 ) + 4 ;
if ( ( V_51 + V_52 ) > V_27 )
break;
V_53 ++ ;
memcpy ( V_3 -> V_20 + V_51 , V_4 -> V_6 , V_4 -> V_38 ) ;
memset ( V_3 -> V_20 + V_51 + V_4 -> V_38 , 0 , V_52 - V_4 -> V_38 ) ;
V_51 += V_52 ;
}
V_54 = V_51 ;
V_50 = (struct V_49 * ) ( V_3 -> V_20 + V_56 ) ;
V_50 -> V_58 = F_30 ( V_59 ) ;
V_50 -> V_60 = F_30 ( V_54 - V_56 -
V_57 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
F_32 ( & V_36 -> V_44 , L_2 , V_54 - V_56 ,
V_3 -> V_20 + V_56 ) ;
for ( V_51 = V_56 ; V_51 < V_54 ; V_51 += V_61 ) {
V_38 = V_54 - V_51 ;
V_38 = V_38 > V_61 ? V_61 : V_38 ;
V_6 = V_3 -> V_20 + V_51 - V_56 ;
V_6 [ 0 ] = V_38 & 0xff ;
V_6 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_6 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_6 [ 3 ] = ( V_51 + V_38 ) >= V_54 ? 0 : 1 ;
F_22 ( V_36 , V_6 , V_38 + V_56 ) ;
}
F_28 ( & V_3 -> V_26 , V_55 ) ;
for ( V_47 = V_3 -> V_24 . V_48 , V_23 = 0 ; V_23 < V_53 ; V_23 ++ , V_47 = V_48 ) {
V_48 = V_47 -> V_48 ;
V_4 = F_10 ( V_47 , struct V_1 , V_15 ) ;
if ( V_4 -> V_62 )
V_4 -> V_62 ( V_4 -> V_63 ) ;
F_11 ( V_47 ) ;
F_12 ( V_4 -> V_2 , V_4 ) ;
}
F_33 ( & V_3 -> V_64 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
}
static void F_34 ( struct V_35 * V_36 , struct V_2 * V_3 ,
struct V_1 * V_4 )
{
unsigned long V_55 ;
F_32 ( & V_36 -> V_44 , L_2 , V_4 -> V_38 - V_56 ,
V_4 -> V_6 + V_56 ) ;
F_22 ( V_36 , V_4 -> V_6 , V_4 -> V_38 ) ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
if ( V_4 -> V_62 )
V_4 -> V_62 ( V_4 -> V_63 ) ;
F_5 ( V_4 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
}
static void F_35 ( struct V_65 * V_66 )
{
struct V_16 * V_17 = F_36 ( V_66 , struct V_16 , V_67 ) ;
struct V_35 * V_36 = V_17 -> V_36 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_1 * V_4 = NULL ;
struct V_68 V_69 , * V_70 ;
int V_71 = 0 ;
long V_72 ;
unsigned long V_55 ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
if ( ! V_3 -> V_73 ) {
F_31 ( & V_3 -> V_26 , V_55 ) ;
return;
}
if ( ! F_9 ( & V_3 -> V_25 ) ) {
V_4 = F_10 ( V_3 -> V_25 . V_48 , struct V_1 , V_15 ) ;
F_11 ( & V_4 -> V_15 ) ;
V_71 = 0 ;
} else if ( ! V_3 -> V_74 && ! F_9 ( & V_3 -> V_24 ) ) {
F_33 ( & V_69 ) ;
V_70 = & V_3 -> V_64 ;
V_72 = ( V_69 . V_75 - V_70 -> V_75 ) * 1000000 +
( V_69 . V_76 - V_70 -> V_76 ) ;
if ( V_72 >= 0 && V_72 < V_77 ) {
F_37 ( & V_17 -> V_67 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
return;
}
V_71 = 1 ;
}
if ( ! V_71 && ! V_4 ) {
F_31 ( & V_3 -> V_26 , V_55 ) ;
return;
}
V_3 -> V_73 = 0 ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
if ( V_71 )
F_27 ( V_36 , V_3 ) ;
else
F_34 ( V_36 , V_3 , V_4 ) ;
}
static int F_38 ( void * V_78 , void * V_37 , int V_38 ,
void (* F_39)( void * V_37 ) , void * V_63 )
{
struct V_16 * V_17 = V_78 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_1 * V_4 ;
T_1 * V_79 = V_37 ;
int V_12 = 0 ;
T_2 V_58 ;
unsigned long V_55 ;
if ( V_38 > V_7 - V_56 )
return - V_80 ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
V_58 = ( V_79 [ 0 ] << 8 ) | V_79 [ 1 ] ;
if ( V_58 == V_81 ) {
V_4 = F_8 ( V_3 , & V_12 ) ;
if ( ! V_4 ) {
F_31 ( & V_3 -> V_26 , V_55 ) ;
return - V_82 ;
}
F_13 ( & V_4 -> V_15 , & V_3 -> V_24 ) ;
memcpy ( V_4 -> V_6 , V_37 , V_38 ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_62 = F_39 ;
V_4 -> V_63 = V_63 ;
} else {
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_31 ( & V_3 -> V_26 , V_55 ) ;
return - V_31 ;
}
F_13 ( & V_4 -> V_15 , & V_3 -> V_25 ) ;
V_4 -> V_6 [ 0 ] = V_38 & 0xff ;
V_4 -> V_6 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_4 -> V_6 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
V_4 -> V_6 [ 3 ] = 2 ;
memcpy ( V_4 -> V_6 + V_56 , V_37 , V_38 ) ;
V_4 -> V_38 = V_38 + V_56 ;
V_4 -> V_62 = F_39 ;
V_4 -> V_63 = V_63 ;
}
if ( V_3 -> V_73 )
F_37 ( & V_17 -> V_67 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
if ( V_12 )
return - V_82 ;
return 0 ;
}
static int F_40 ( struct V_16 * V_17 , T_1 * V_83 , int V_38 )
{
struct V_2 * V_3 = & V_17 -> V_3 ;
T_2 V_58 ;
unsigned long V_55 ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
V_58 = ( V_83 [ 0 ] << 8 ) | ( V_83 [ 1 ] ) ;
if ( V_58 != V_84 )
goto V_85;
if ( V_83 [ 4 ] == 0 ) {
F_32 ( & V_17 -> V_36 -> V_44 , L_3 ) ;
V_3 -> V_74 = 1 ;
} else if ( V_83 [ 4 ] == 1 ) {
F_32 ( & V_17 -> V_36 -> V_44 , L_4 ) ;
V_3 -> V_74 = 0 ;
if ( V_3 -> V_73 )
F_37 ( & V_17 -> V_67 ) ;
if ( F_9 ( & V_3 -> V_13 ) )
V_38 = 0 ;
}
V_85:
F_31 ( & V_3 -> V_26 , V_55 ) ;
return V_38 ;
}
static void F_41 ( struct V_35 * V_36 )
{
struct V_86 * V_86 = F_42 ( V_36 ) ;
struct V_16 * V_17 = V_86 -> V_78 ;
struct V_2 * V_3 = & V_17 -> V_3 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_8 * V_11 ;
unsigned long V_55 ;
T_1 V_87 , V_88 [ V_89 ] , * V_6 ;
T_3 V_38 , V_40 , V_39 ;
int V_22 , V_41 ;
V_87 = F_43 ( V_36 , 0x13 , & V_22 ) ;
if ( V_87 & 0x01 )
F_44 ( V_36 , 0x01 , 0x13 , & V_22 ) ;
else
return;
V_22 = F_45 ( V_36 , V_88 , 0x0 , V_89 ) ;
if ( V_22 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_90 ) ;
goto V_91;
}
V_38 = ( V_88 [ 2 ] << 16 ) | ( V_88 [ 1 ] << 8 ) | V_88 [ 0 ] ;
if ( V_38 > ( V_34 - V_56 ) ) {
F_25 ( & V_36 -> V_44 , L_6 , V_38 ) ;
goto V_91;
}
if ( V_88 [ 3 ] == 1 ) {
T_3 * V_92 = ( T_3 * ) & V_88 [ 4 ] ;
F_28 ( & V_3 -> V_26 , V_55 ) ;
V_3 -> V_73 = 1 ;
if ( ! F_9 ( & V_3 -> V_24 ) || ! F_9 ( & V_3 -> V_25 ) )
F_37 ( & V_17 -> V_67 ) ;
F_31 ( & V_3 -> V_26 , V_55 ) ;
F_32 ( & V_36 -> V_44 , L_7 , F_46 ( * V_92 ) ) ;
goto V_91;
}
memcpy ( V_10 -> V_21 , V_88 + V_56 ,
V_89 - V_56 ) ;
V_6 = V_10 -> V_21 + V_89 - V_56 ;
V_41 = V_38 - V_89 + V_56 ;
if ( V_41 <= 0 )
goto V_45;
V_40 = V_41 / V_36 -> V_42 ;
if ( V_40 ) {
V_39 = V_40 * V_36 -> V_42 ;
V_22 = F_45 ( V_36 , V_6 , 0x0 , V_39 ) ;
if ( V_22 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_90 ) ;
goto V_91;
}
V_6 += V_39 ;
V_41 -= V_39 ;
}
if ( V_41 ) {
V_22 = F_45 ( V_36 , V_6 , 0x0 , V_41 ) ;
if ( V_22 ) {
F_25 ( & V_36 -> V_44 ,
L_5 , V_36 -> V_90 ) ;
goto V_91;
}
}
V_45:
F_32 ( & V_36 -> V_44 , L_8 , V_38 , V_10 -> V_21 ) ;
V_38 = F_40 ( V_17 , V_10 -> V_21 , V_38 ) ;
F_28 ( & V_10 -> V_26 , V_55 ) ;
if ( ! F_9 ( & V_10 -> V_32 ) ) {
V_11 = F_10 ( V_10 -> V_32 . V_48 , struct V_8 , V_15 ) ;
F_31 ( & V_10 -> V_26 , V_55 ) ;
if ( V_11 -> V_62 )
V_11 -> V_62 ( V_11 -> V_63 , V_10 -> V_21 , V_38 ) ;
F_28 ( & V_10 -> V_26 , V_55 ) ;
F_11 ( & V_11 -> V_15 ) ;
F_15 ( V_10 , V_11 ) ;
}
F_31 ( & V_10 -> V_26 , V_55 ) ;
V_91:
F_44 ( V_36 , 0x00 , 0x10 , & V_22 ) ;
if ( ! V_86 -> V_93 )
F_47 ( V_86 , & V_36 -> V_44 ) ;
}
static int F_48 ( void * V_78 ,
void (* F_39)( void * V_63 , void * V_37 , int V_38 ) ,
void * V_63 )
{
struct V_16 * V_17 = V_78 ;
struct V_9 * V_10 = & V_17 -> V_10 ;
struct V_8 * V_11 ;
unsigned long V_55 ;
F_28 ( & V_10 -> V_26 , V_55 ) ;
V_11 = F_14 ( V_10 ) ;
if ( ! V_11 ) {
F_31 ( & V_10 -> V_26 , V_55 ) ;
return - V_31 ;
}
V_11 -> V_62 = F_39 ;
V_11 -> V_63 = V_63 ;
F_13 ( & V_11 -> V_15 , & V_10 -> V_32 ) ;
F_31 ( & V_10 -> V_26 , V_55 ) ;
return 0 ;
}
static int F_49 ( struct V_35 * V_36 ,
const struct V_94 * V_95 )
{
int V_22 ;
struct V_86 * V_86 = NULL ;
struct V_16 * V_17 = NULL ;
F_50 ( & V_36 -> V_44 , L_9 ,
V_36 -> V_96 , V_36 -> V_97 ) ;
F_50 ( & V_36 -> V_44 , L_10 , V_98 ) ;
F_23 ( V_36 ) ;
F_51 ( V_36 ) ;
F_52 ( V_36 , F_41 ) ;
V_22 = F_53 ( V_36 ) ;
if ( V_22 )
return V_22 ;
V_86 = F_2 ( sizeof( * V_86 ) , V_28 ) ;
if ( ! V_86 ) {
V_22 = - V_31 ;
goto V_85;
}
V_17 = F_2 ( sizeof( * V_17 ) , V_28 ) ;
if ( ! V_17 ) {
V_22 = - V_31 ;
goto V_85;
}
V_86 -> V_78 = ( void * ) V_17 ;
V_86 -> V_99 = F_38 ;
V_86 -> V_100 = F_48 ;
V_22 = F_18 ( V_17 ) ;
if ( V_22 < 0 )
goto V_85;
V_17 -> V_36 = V_36 ;
F_44 ( V_36 , 1 , 0x14 , & V_22 ) ;
F_26 ( V_36 ) ;
F_54 ( & V_17 -> V_67 , F_35 ) ;
F_55 ( V_36 , V_86 ) ;
V_85:
if ( V_22 ) {
F_4 ( V_86 ) ;
F_4 ( V_17 ) ;
}
return V_22 ;
}
static void F_56 ( struct V_35 * V_36 )
{
struct V_86 * V_86 = F_42 ( V_36 ) ;
struct V_16 * V_17 = V_86 -> V_78 ;
F_57 ( & V_17 -> V_67 ) ;
if ( V_86 -> V_93 )
F_58 ( V_86 ) ;
F_23 ( V_36 ) ;
F_59 ( V_36 ) ;
F_60 ( V_36 ) ;
F_26 ( V_36 ) ;
F_16 ( V_17 ) ;
F_4 ( V_17 ) ;
F_4 ( V_86 ) ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_101 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_101 ) ;
}

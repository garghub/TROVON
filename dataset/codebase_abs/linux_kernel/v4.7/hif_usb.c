static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
break;
}
if ( V_3 ) {
F_2 ( V_3 -> V_10 -> V_11 ,
V_3 -> V_12 , true ) ;
F_3 ( V_3 ) ;
}
return;
free:
F_4 ( V_3 -> V_12 ) ;
F_3 ( V_3 ) ;
}
static int F_5 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
int V_15 = 0 ;
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL )
return - V_17 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_16 ) ;
if ( V_3 == NULL ) {
F_8 ( V_1 ) ;
return - V_17 ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_10 = V_10 ;
F_9 ( V_1 , V_10 -> V_18 ,
F_10 ( V_10 -> V_18 , V_19 ) ,
V_12 -> V_20 , V_12 -> V_21 ,
F_1 , V_3 , 1 ) ;
F_11 ( V_1 , & V_10 -> V_22 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
F_3 ( V_3 ) ;
}
F_8 ( V_1 ) ;
return V_15 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_13 * V_10 ;
bool V_23 = true ;
if ( ! V_3 || ! V_3 -> V_12 || ! V_3 -> V_10 )
return;
V_10 = V_3 -> V_10 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
V_23 = false ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
if ( V_10 -> V_24 . V_26 & V_27 ) {
F_16 ( & V_10 -> V_24 . V_25 ) ;
F_17 ( V_3 -> V_12 ) ;
F_3 ( V_3 ) ;
return;
}
F_16 ( & V_10 -> V_24 . V_25 ) ;
break;
default:
V_23 = false ;
break;
}
F_18 ( V_3 -> V_12 , 4 ) ;
F_2 ( V_3 -> V_10 -> V_11 ,
V_3 -> V_12 , V_23 ) ;
F_3 ( V_3 ) ;
}
static int F_19 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
int V_15 = 0 ;
T_1 * V_28 ;
V_1 = F_6 ( 0 , V_29 ) ;
if ( V_1 == NULL )
return - V_17 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_29 ) ;
if ( V_3 == NULL ) {
F_8 ( V_1 ) ;
return - V_17 ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_10 = V_10 ;
V_28 = ( T_1 * ) F_20 ( V_12 , 4 ) ;
* V_28 ++ = F_21 ( V_12 -> V_21 - 4 ) ;
* V_28 ++ = F_21 ( V_30 ) ;
F_22 ( V_1 , V_10 -> V_18 ,
F_23 ( V_10 -> V_18 , V_31 ) ,
V_12 -> V_20 , V_12 -> V_21 ,
F_14 , V_3 ) ;
F_11 ( V_1 , & V_10 -> V_32 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
F_3 ( V_3 ) ;
}
F_8 ( V_1 ) ;
return V_15 ;
}
static inline void F_24 ( struct V_13 * V_10 ,
struct V_33 * V_34 )
{
struct V_14 * V_12 ;
while ( ( V_12 = F_25 ( V_34 ) ) != NULL ) {
F_17 ( V_12 ) ;
}
}
static inline void F_26 ( struct V_13 * V_10 ,
struct V_33 * V_35 ,
bool V_23 )
{
struct V_14 * V_12 ;
while ( ( V_12 = F_25 ( V_35 ) ) != NULL ) {
#ifdef F_27
int V_36 = V_12 -> V_21 ;
#endif
F_2 ( V_10 -> V_11 ,
V_12 , V_23 ) ;
if ( V_23 ) {
F_28 ( V_37 ) ;
F_29 ( V_38 , V_36 ) ;
}
else
F_28 ( V_39 ) ;
}
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_40 * V_40 = (struct V_40 * ) V_1 -> V_4 ;
struct V_13 * V_10 ;
bool V_23 = true ;
if ( ! V_40 || ! V_40 -> V_10 )
return;
V_10 = V_40 -> V_10 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
V_23 = false ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
if ( V_10 -> V_24 . V_26 & V_27 ) {
F_16 ( & V_10 -> V_24 . V_25 ) ;
F_24 ( V_10 , & V_40 -> V_41 ) ;
return;
}
F_16 ( & V_10 -> V_24 . V_25 ) ;
break;
default:
V_23 = false ;
break;
}
F_26 ( V_10 , & V_40 -> V_41 , V_23 ) ;
V_40 -> V_21 = V_40 -> V_42 = 0 ;
F_31 ( & V_40 -> V_41 ) ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
F_32 ( & V_40 -> V_34 , & V_10 -> V_24 . V_40 ) ;
V_10 -> V_24 . V_43 ++ ;
if ( ! ( V_10 -> V_24 . V_26 & V_44 ) )
F_33 ( V_10 ) ;
F_28 ( V_45 ) ;
F_16 ( & V_10 -> V_24 . V_25 ) ;
}
static int F_33 ( struct V_13 * V_10 )
{
struct V_40 * V_40 = NULL ;
struct V_14 * V_46 = NULL ;
int V_15 = 0 , V_47 ;
T_2 V_48 = 0 ;
T_3 * V_49 ;
T_1 * V_28 ;
if ( V_10 -> V_24 . V_48 == 0 )
return 0 ;
if ( F_34 ( & V_10 -> V_24 . V_40 ) )
return 0 ;
V_40 = F_35 ( & V_10 -> V_24 . V_40 , struct V_40 , V_34 ) ;
F_32 ( & V_40 -> V_34 , & V_10 -> V_24 . V_50 ) ;
V_10 -> V_24 . V_43 -- ;
V_48 = F_36 ( T_2 , V_10 -> V_24 . V_48 , V_51 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_46 = F_25 ( & V_10 -> V_24 . V_52 ) ;
F_37 ( ! V_46 ) ;
V_10 -> V_24 . V_48 -- ;
V_49 = V_40 -> V_49 ;
V_49 += V_40 -> V_42 ;
V_28 = ( T_1 * ) V_49 ;
* V_28 ++ = F_21 ( V_46 -> V_21 ) ;
* V_28 ++ = F_21 ( V_30 ) ;
V_49 += 4 ;
memcpy ( V_49 , V_46 -> V_20 , V_46 -> V_21 ) ;
V_40 -> V_21 = V_46 -> V_21 + 4 ;
if ( V_47 < ( V_48 - 1 ) )
V_40 -> V_42 += ( ( ( V_40 -> V_21 - 1 ) / 4 ) + 1 ) * 4 ;
if ( V_47 == ( V_48 - 1 ) )
V_40 -> V_21 += V_40 -> V_42 ;
F_38 ( & V_40 -> V_41 , V_46 ) ;
F_28 ( V_53 ) ;
}
F_22 ( V_40 -> V_1 , V_10 -> V_18 ,
F_23 ( V_10 -> V_18 , V_31 ) ,
V_40 -> V_49 , V_40 -> V_21 ,
F_30 , V_40 ) ;
V_15 = F_12 ( V_40 -> V_1 , V_29 ) ;
if ( V_15 ) {
V_40 -> V_21 = V_40 -> V_42 = 0 ;
F_26 ( V_10 , & V_40 -> V_41 , false ) ;
F_31 ( & V_40 -> V_41 ) ;
F_32 ( & V_40 -> V_34 , & V_10 -> V_24 . V_40 ) ;
V_10 -> V_24 . V_43 ++ ;
}
if ( ! V_15 )
F_28 ( V_54 ) ;
return V_15 ;
}
static int F_39 ( struct V_13 * V_10 , struct V_14 * V_12 )
{
struct V_55 * V_56 ;
unsigned long V_26 ;
int V_15 = 0 ;
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
if ( V_10 -> V_24 . V_26 & V_44 ) {
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return - V_8 ;
}
if ( V_10 -> V_24 . V_48 > V_57 ) {
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return - V_17 ;
}
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_56 = F_42 ( V_12 ) ;
if ( ( V_56 -> type == V_58 ) ||
( V_56 -> type == V_59 ) ) {
V_15 = F_19 ( V_10 , V_12 ) ;
}
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
if ( ( V_56 -> type == V_60 ) ||
( V_56 -> type == V_61 ) ) {
F_38 ( & V_10 -> V_24 . V_52 , V_12 ) ;
V_10 -> V_24 . V_48 ++ ;
}
if ( ( V_10 -> V_24 . V_43 == V_62 ) &&
( V_10 -> V_24 . V_48 < 2 ) ) {
F_33 ( V_10 ) ;
}
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return V_15 ;
}
static void F_43 ( void * V_63 )
{
struct V_13 * V_10 = (struct V_13 * ) V_63 ;
unsigned long V_26 ;
V_10 -> V_26 |= V_64 ;
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_10 -> V_24 . V_26 &= ~ V_44 ;
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
}
static void F_44 ( void * V_63 )
{
struct V_13 * V_10 = (struct V_13 * ) V_63 ;
struct V_40 * V_40 = NULL , * V_65 = NULL ;
unsigned long V_26 ;
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_26 ( V_10 , & V_10 -> V_24 . V_52 , false ) ;
V_10 -> V_24 . V_48 = 0 ;
V_10 -> V_24 . V_26 |= V_44 ;
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_45 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_pending, list) {
F_46 ( V_40 -> V_1 ) ;
}
F_47 ( & V_10 -> V_32 ) ;
}
static int F_48 ( void * V_63 , T_3 V_66 , struct V_14 * V_12 )
{
struct V_13 * V_10 = (struct V_13 * ) V_63 ;
int V_15 = 0 ;
switch ( V_66 ) {
case V_31 :
V_15 = F_39 ( V_10 , V_12 ) ;
break;
case V_19 :
V_15 = F_5 ( V_10 , V_12 ) ;
break;
default:
F_49 ( & V_10 -> V_18 -> V_67 ,
L_1 , V_66 ) ;
V_15 = - V_68 ;
break;
}
return V_15 ;
}
static inline bool F_50 ( struct V_14 * V_12 , T_3 V_69 )
{
struct V_55 * V_56 ;
V_56 = F_42 ( V_12 ) ;
if ( ( V_56 -> type == V_61 ) &&
( V_56 -> V_70 == V_69 ) )
return true ;
return false ;
}
static void F_51 ( void * V_63 , T_3 V_69 )
{
struct V_13 * V_10 = (struct V_13 * ) V_63 ;
struct V_14 * V_12 , * V_71 ;
unsigned long V_26 ;
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_52 (&hif_dev->tx.tx_skb_queue, skb, tmp) {
if ( F_50 ( V_12 , V_69 ) ) {
F_53 ( V_12 , & V_10 -> V_24 . V_52 ) ;
F_2 ( V_10 -> V_11 ,
V_12 , false ) ;
V_10 -> V_24 . V_48 -- ;
F_28 ( V_39 ) ;
}
}
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
}
static void F_54 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_14 * V_46 , * V_72 [ V_73 ] ;
int V_74 = 0 , V_47 , V_21 = V_12 -> V_21 ;
int V_75 , V_76 ;
T_2 V_77 = 0 ;
T_3 * V_78 ;
F_15 ( & V_10 -> V_79 ) ;
V_75 = V_10 -> V_75 ;
V_76 = V_10 -> V_80 ;
if ( V_75 != 0 ) {
struct V_14 * V_81 = V_10 -> V_81 ;
if ( V_81 ) {
V_78 = ( T_3 * ) V_81 -> V_20 ;
V_74 = V_75 ;
V_75 -= V_10 -> V_82 ;
V_78 += V_76 ;
memcpy ( V_78 , V_12 -> V_20 , V_75 ) ;
V_76 += V_75 ;
V_10 -> V_75 = 0 ;
F_55 ( V_81 , V_76 ) ;
V_72 [ V_77 ++ ] = V_81 ;
} else {
V_74 = V_75 ;
}
}
F_16 ( & V_10 -> V_79 ) ;
while ( V_74 < V_21 ) {
T_2 V_83 ;
T_2 V_84 ;
T_2 V_85 ;
int V_86 ;
V_78 = ( T_3 * ) V_12 -> V_20 ;
V_83 = F_56 ( V_78 + V_74 ) ;
V_84 = F_56 ( V_78 + V_74 + 2 ) ;
if ( V_84 != V_87 ) {
F_57 ( V_88 ) ;
return;
}
V_85 = 4 - ( V_83 & 0x3 ) ;
if ( V_85 == 4 )
V_85 = 0 ;
V_86 = V_74 ;
V_74 = V_74 + 4 + V_83 + V_85 ;
if ( V_74 > V_89 ) {
F_15 ( & V_10 -> V_79 ) ;
V_10 -> V_75 = V_74 - V_89 ;
V_10 -> V_80 =
V_89 - V_86 - 4 ;
V_10 -> V_82 = V_85 ;
V_46 = F_58 ( V_83 + 32 , V_29 ) ;
if ( ! V_46 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_2 ) ;
F_16 ( & V_10 -> V_79 ) ;
goto V_90;
}
F_59 ( V_46 , 32 ) ;
F_57 ( V_91 ) ;
memcpy ( V_46 -> V_20 , & ( V_12 -> V_20 [ V_86 + 4 ] ) ,
V_10 -> V_80 ) ;
V_10 -> V_81 = V_46 ;
F_16 ( & V_10 -> V_79 ) ;
} else {
V_46 = F_58 ( V_83 + 32 , V_29 ) ;
if ( ! V_46 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_2 ) ;
goto V_90;
}
F_59 ( V_46 , 32 ) ;
F_57 ( V_91 ) ;
memcpy ( V_46 -> V_20 , & ( V_12 -> V_20 [ V_86 + 4 ] ) , V_83 ) ;
F_55 ( V_46 , V_83 ) ;
V_72 [ V_77 ++ ] = V_46 ;
}
}
V_90:
for ( V_47 = 0 ; V_47 < V_77 ; V_47 ++ ) {
F_60 ( V_92 , V_72 [ V_47 ] -> V_21 ) ;
F_61 ( V_10 -> V_11 , V_72 [ V_47 ] ,
V_72 [ V_47 ] -> V_21 , V_93 ) ;
F_57 ( V_94 ) ;
}
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_14 * V_12 = (struct V_14 * ) V_1 -> V_4 ;
struct V_13 * V_10 =
F_63 ( F_64 ( V_1 -> V_67 , 0 ) ) ;
int V_15 ;
if ( ! V_12 )
return;
if ( ! V_10 )
goto free;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
goto V_95;
}
if ( F_65 ( V_1 -> V_96 != 0 ) ) {
F_55 ( V_12 , V_1 -> V_96 ) ;
F_54 ( V_10 , V_12 ) ;
}
V_95:
F_66 ( V_12 ) ;
F_67 ( V_12 , 0 ) ;
F_11 ( V_1 , & V_10 -> V_97 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto free;
}
return;
free:
F_4 ( V_12 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
struct V_14 * V_12 = (struct V_14 * ) V_1 -> V_4 ;
struct V_14 * V_46 ;
struct V_13 * V_10 =
F_63 ( F_64 ( V_1 -> V_67 , 0 ) ) ;
int V_15 ;
if ( ! V_12 )
return;
if ( ! V_10 )
goto free;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
F_66 ( V_12 ) ;
F_67 ( V_12 , 0 ) ;
goto V_95;
}
if ( F_65 ( V_1 -> V_96 != 0 ) ) {
F_55 ( V_12 , V_1 -> V_96 ) ;
F_61 ( V_10 -> V_11 , V_12 ,
V_12 -> V_21 , V_98 ) ;
V_46 = F_69 ( V_99 , V_29 ) ;
if ( ! V_46 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_3 ) ;
V_1 -> V_4 = NULL ;
return;
}
F_9 ( V_1 , V_10 -> V_18 ,
F_70 ( V_10 -> V_18 ,
V_98 ) ,
V_46 -> V_20 , V_99 ,
F_68 , V_46 , 1 ) ;
}
V_95:
F_11 ( V_1 , & V_10 -> V_100 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto free;
}
return;
free:
F_4 ( V_12 ) ;
V_1 -> V_4 = NULL ;
}
static void F_71 ( struct V_13 * V_10 )
{
struct V_40 * V_40 = NULL , * V_65 = NULL ;
unsigned long V_26 ;
F_45 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_buf, list) {
F_46 ( V_40 -> V_1 ) ;
F_72 ( & V_40 -> V_34 ) ;
F_8 ( V_40 -> V_1 ) ;
F_3 ( V_40 -> V_49 ) ;
F_3 ( V_40 ) ;
}
F_40 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_10 -> V_24 . V_26 |= V_27 ;
F_41 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_45 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_pending, list) {
F_46 ( V_40 -> V_1 ) ;
F_72 ( & V_40 -> V_34 ) ;
F_8 ( V_40 -> V_1 ) ;
F_3 ( V_40 -> V_49 ) ;
F_3 ( V_40 ) ;
}
F_47 ( & V_10 -> V_32 ) ;
}
static int F_73 ( struct V_13 * V_10 )
{
struct V_40 * V_40 ;
int V_47 ;
F_74 ( & V_10 -> V_24 . V_40 ) ;
F_74 ( & V_10 -> V_24 . V_50 ) ;
F_75 ( & V_10 -> V_24 . V_25 ) ;
F_31 ( & V_10 -> V_24 . V_52 ) ;
F_76 ( & V_10 -> V_32 ) ;
for ( V_47 = 0 ; V_47 < V_62 ; V_47 ++ ) {
V_40 = F_7 ( sizeof( struct V_40 ) , V_16 ) ;
if ( ! V_40 )
goto V_90;
V_40 -> V_49 = F_7 ( V_101 , V_16 ) ;
if ( ! V_40 -> V_49 )
goto V_90;
V_40 -> V_1 = F_6 ( 0 , V_16 ) ;
if ( ! V_40 -> V_1 )
goto V_90;
V_40 -> V_10 = V_10 ;
F_31 ( & V_40 -> V_41 ) ;
F_77 ( & V_40 -> V_34 , & V_10 -> V_24 . V_40 ) ;
}
V_10 -> V_24 . V_43 = V_62 ;
return 0 ;
V_90:
if ( V_40 ) {
F_3 ( V_40 -> V_49 ) ;
F_3 ( V_40 ) ;
}
F_71 ( V_10 ) ;
return - V_17 ;
}
static void F_78 ( struct V_13 * V_10 )
{
F_47 ( & V_10 -> V_97 ) ;
}
static int F_79 ( struct V_13 * V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_14 * V_12 = NULL ;
int V_47 , V_15 ;
F_76 ( & V_10 -> V_97 ) ;
F_75 ( & V_10 -> V_79 ) ;
for ( V_47 = 0 ; V_47 < V_102 ; V_47 ++ ) {
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL ) {
V_15 = - V_17 ;
goto V_103;
}
V_12 = F_69 ( V_89 , V_16 ) ;
if ( ! V_12 ) {
V_15 = - V_17 ;
goto V_104;
}
F_22 ( V_1 , V_10 -> V_18 ,
F_80 ( V_10 -> V_18 ,
V_93 ) ,
V_12 -> V_20 , V_89 ,
F_62 , V_12 ) ;
F_11 ( V_1 , & V_10 -> V_97 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto V_105;
}
F_8 ( V_1 ) ;
}
return 0 ;
V_105:
F_4 ( V_12 ) ;
V_104:
F_8 ( V_1 ) ;
V_103:
F_78 ( V_10 ) ;
return V_15 ;
}
static void F_81 ( struct V_13 * V_10 )
{
F_47 ( & V_10 -> V_100 ) ;
}
static int F_82 ( struct V_13 * V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_14 * V_12 = NULL ;
int V_47 , V_15 ;
F_76 ( & V_10 -> V_100 ) ;
for ( V_47 = 0 ; V_47 < V_106 ; V_47 ++ ) {
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL ) {
V_15 = - V_17 ;
goto V_103;
}
V_12 = F_69 ( V_99 , V_16 ) ;
if ( ! V_12 ) {
V_15 = - V_17 ;
goto V_104;
}
F_9 ( V_1 , V_10 -> V_18 ,
F_70 ( V_10 -> V_18 ,
V_98 ) ,
V_12 -> V_20 , V_99 ,
F_68 , V_12 , 1 ) ;
F_11 ( V_1 , & V_10 -> V_100 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto V_105;
}
F_8 ( V_1 ) ;
}
return 0 ;
V_105:
F_4 ( V_12 ) ;
V_104:
F_8 ( V_1 ) ;
V_103:
F_81 ( V_10 ) ;
return V_15 ;
}
static int F_83 ( struct V_13 * V_10 )
{
F_76 ( & V_10 -> V_22 ) ;
if ( F_73 ( V_10 ) < 0 )
goto V_90;
if ( F_79 ( V_10 ) < 0 )
goto V_107;
if ( F_82 ( V_10 ) < 0 )
goto V_108;
return 0 ;
V_108:
F_78 ( V_10 ) ;
V_107:
F_71 ( V_10 ) ;
V_90:
return - V_17 ;
}
static void F_84 ( struct V_13 * V_10 )
{
F_47 ( & V_10 -> V_22 ) ;
F_81 ( V_10 ) ;
F_71 ( V_10 ) ;
F_78 ( V_10 ) ;
}
static int F_85 ( struct V_13 * V_10 )
{
int V_109 , V_90 ;
const void * V_20 = V_10 -> V_110 ;
T_4 V_21 = V_10 -> V_111 ;
T_5 V_112 = V_113 ;
T_3 * V_49 = F_7 ( 4096 , V_16 ) ;
T_5 V_114 ;
if ( ! V_49 )
return - V_17 ;
while ( V_21 ) {
V_109 = F_36 ( T_4 , V_21 , 4096 ) ;
memcpy ( V_49 , V_20 , V_109 ) ;
V_90 = F_86 ( V_10 -> V_18 ,
F_87 ( V_10 -> V_18 , 0 ) ,
V_115 , 0x40 | V_116 ,
V_112 >> 8 , 0 , V_49 , V_109 , V_117 ) ;
if ( V_90 < 0 ) {
F_3 ( V_49 ) ;
return V_90 ;
}
V_21 -= V_109 ;
V_20 += V_109 ;
V_112 += V_109 ;
}
F_3 ( V_49 ) ;
if ( F_88 ( V_10 -> V_118 -> V_119 ) )
V_114 = V_120 ;
else
V_114 = V_121 ;
V_90 = F_86 ( V_10 -> V_18 , F_87 ( V_10 -> V_18 , 0 ) ,
V_122 ,
0x40 | V_116 ,
V_114 >> 8 , 0 , NULL , 0 , V_117 ) ;
if ( V_90 )
return - V_123 ;
F_89 ( & V_10 -> V_18 -> V_67 , L_4 ,
V_10 -> V_124 , ( unsigned long ) V_10 -> V_111 ) ;
return 0 ;
}
static int F_90 ( struct V_13 * V_10 )
{
int V_15 ;
V_15 = F_85 ( V_10 ) ;
if ( V_15 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_5 ,
V_10 -> V_124 ) ;
return V_15 ;
}
V_15 = F_83 ( V_10 ) ;
if ( V_15 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_6 ) ;
return V_15 ;
}
return 0 ;
}
static void F_91 ( struct V_13 * V_10 )
{
F_84 ( V_10 ) ;
}
static void F_92 ( struct V_13 * V_10 )
{
struct V_125 * V_67 = & V_10 -> V_18 -> V_67 ;
struct V_125 * V_126 = V_67 -> V_126 ;
F_93 ( & V_10 -> V_127 ) ;
if ( V_126 )
F_94 ( V_126 ) ;
F_95 ( V_67 ) ;
if ( V_126 )
F_96 ( V_126 ) ;
}
static int F_97 ( struct V_13 * V_10 ,
bool V_128 )
{
char V_74 [ 8 ] , * V_129 ;
int V_15 ;
if ( V_128 ) {
if ( V_130 ) {
V_10 -> V_131 = V_132 + 1 ;
sprintf ( V_74 , L_7 , L_8 ) ;
} else {
V_10 -> V_131 = V_132 ;
sprintf ( V_74 , L_9 , V_10 -> V_131 ) ;
}
} else {
V_10 -> V_131 -- ;
sprintf ( V_74 , L_9 , V_10 -> V_131 ) ;
}
if ( V_133 == 1 && V_10 -> V_131 == 3 ) {
const char * V_134 ;
if ( F_88 ( V_10 -> V_118 -> V_119 ) )
V_134 = V_135 ;
else
V_134 = V_136 ;
snprintf ( V_10 -> V_124 , sizeof( V_10 -> V_124 ) ,
L_7 , V_134 ) ;
} else if ( V_10 -> V_131 < V_137 ) {
F_49 ( & V_10 -> V_18 -> V_67 , L_10 ) ;
return - V_6 ;
} else {
if ( F_88 ( V_10 -> V_118 -> V_119 ) )
V_129 = L_11 ;
else
V_129 = L_12 ;
snprintf ( V_10 -> V_124 , sizeof( V_10 -> V_124 ) ,
L_13 , V_138 ,
V_129 , V_133 , V_74 ) ;
}
V_15 = F_98 ( V_139 , true , V_10 -> V_124 ,
& V_10 -> V_18 -> V_67 , V_16 ,
V_10 , V_140 ) ;
if ( V_15 ) {
F_49 ( & V_10 -> V_18 -> V_67 ,
L_14 ,
V_10 -> V_124 ) ;
return V_15 ;
}
F_89 ( & V_10 -> V_18 -> V_67 , L_15 ,
V_10 -> V_124 ) ;
return V_15 ;
}
static void V_140 ( const struct V_141 * V_142 , void * V_4 )
{
struct V_13 * V_10 = V_4 ;
int V_15 ;
if ( ! V_142 ) {
V_15 = F_97 ( V_10 , false ) ;
if ( ! V_15 )
return;
F_49 ( & V_10 -> V_18 -> V_67 ,
L_16 ,
V_10 -> V_124 ) ;
goto V_143;
}
V_10 -> V_11 = F_99 ( V_10 , & V_144 ,
& V_10 -> V_18 -> V_67 ) ;
if ( V_10 -> V_11 == NULL )
goto V_145;
V_10 -> V_110 = V_142 -> V_20 ;
V_10 -> V_111 = V_142 -> V_146 ;
V_15 = F_90 ( V_10 ) ;
if ( V_15 )
goto V_147;
V_15 = F_100 ( V_10 -> V_11 ,
& V_10 -> V_148 -> V_67 ,
V_10 -> V_118 -> V_149 ,
V_10 -> V_18 -> V_150 ,
V_10 -> V_118 -> V_119 ) ;
if ( V_15 ) {
V_15 = - V_68 ;
goto V_151;
}
F_101 ( V_142 ) ;
V_10 -> V_26 |= V_152 ;
F_93 ( & V_10 -> V_127 ) ;
return;
V_151:
F_91 ( V_10 ) ;
V_147:
F_102 ( V_10 -> V_11 ) ;
V_145:
F_101 ( V_142 ) ;
V_143:
F_92 ( V_10 ) ;
}
static int F_103 ( struct V_153 * V_148 )
{
struct V_154 * V_18 = F_104 ( V_148 ) ;
struct V_155 * V_156 = & V_148 -> V_157 [ 0 ] ;
struct V_158 * V_159 ;
unsigned char * V_3 ;
T_3 V_160 ;
int V_161 ;
for ( V_161 = 1 ; V_161 >= 0 ; V_161 -- ) {
V_159 = & V_156 -> V_159 [ V_161 ] . V_162 ;
if ( F_105 ( V_159 ) &&
F_106 ( V_159 ) ) {
V_160 = V_159 -> V_163 ;
break;
}
}
if ( V_161 == - 1 ) {
F_49 ( & V_18 -> V_67 ,
L_17 ) ;
return - V_8 ;
}
V_3 = F_7 ( 31 , V_16 ) ;
if ( V_3 == NULL )
return - V_8 ;
V_3 [ 0 ] = 0x55 ;
V_3 [ 1 ] = 0x53 ;
V_3 [ 2 ] = 0x42 ;
V_3 [ 3 ] = 0x43 ;
V_3 [ 14 ] = 6 ;
V_3 [ 15 ] = 0x1b ;
V_3 [ 19 ] = 0x2 ;
F_89 ( & V_18 -> V_67 , L_18 ) ;
V_161 = F_107 ( V_18 , F_23 ( V_18 , V_160 ) ,
V_3 , 31 , NULL , 2000 ) ;
F_3 ( V_3 ) ;
if ( V_161 )
return V_161 ;
F_108 ( V_148 , NULL ) ;
return 0 ;
}
static int F_109 ( struct V_153 * V_148 ,
const struct V_118 * V_164 )
{
struct V_154 * V_18 = F_104 ( V_148 ) ;
struct V_13 * V_10 ;
int V_15 = 0 ;
if ( V_164 -> V_119 == V_165 )
return F_103 ( V_148 ) ;
V_10 = F_7 ( sizeof( struct V_13 ) , V_16 ) ;
if ( ! V_10 ) {
V_15 = - V_17 ;
goto V_166;
}
F_110 ( V_18 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_148 = V_148 ;
V_10 -> V_118 = V_164 ;
#ifdef F_111
V_18 -> V_167 = 1 ;
#endif
F_108 ( V_148 , V_10 ) ;
F_112 ( & V_10 -> V_127 ) ;
V_15 = F_97 ( V_10 , true ) ;
if ( V_15 )
goto V_168;
return V_15 ;
V_168:
F_108 ( V_148 , NULL ) ;
F_3 ( V_10 ) ;
F_113 ( V_18 ) ;
V_166:
return V_15 ;
}
static void F_114 ( struct V_154 * V_18 )
{
T_5 V_169 = 0xffffffff ;
void * V_49 ;
int V_15 ;
V_49 = F_115 ( & V_169 , 4 , V_16 ) ;
if ( ! V_49 )
return;
V_15 = F_116 ( V_18 , F_10 ( V_18 , V_19 ) ,
V_49 , 4 , NULL , V_117 ) ;
if ( V_15 )
F_49 ( & V_18 -> V_67 , L_19 ) ;
F_3 ( V_49 ) ;
}
static void F_117 ( struct V_153 * V_148 )
{
struct V_154 * V_18 = F_104 ( V_148 ) ;
struct V_13 * V_10 = F_63 ( V_148 ) ;
bool V_170 = ( V_18 -> V_171 == V_172 ) ? true : false ;
if ( ! V_10 )
return;
F_118 ( & V_10 -> V_127 ) ;
if ( V_10 -> V_26 & V_152 ) {
F_119 ( V_10 -> V_11 , V_170 ) ;
F_102 ( V_10 -> V_11 ) ;
F_91 ( V_10 ) ;
}
F_108 ( V_148 , NULL ) ;
if ( ! V_170 && ( V_10 -> V_26 & V_152 ) )
F_114 ( V_18 ) ;
F_3 ( V_10 ) ;
F_89 ( & V_18 -> V_67 , L_20 ) ;
F_113 ( V_18 ) ;
}
static int F_120 ( struct V_153 * V_148 ,
T_6 V_173 )
{
struct V_13 * V_10 = F_63 ( V_148 ) ;
if ( ! ( V_10 -> V_26 & V_64 ) )
F_121 ( V_10 -> V_11 ) ;
F_118 ( & V_10 -> V_127 ) ;
if ( V_10 -> V_26 & V_152 )
F_84 ( V_10 ) ;
return 0 ;
}
static int F_122 ( struct V_153 * V_148 )
{
struct V_13 * V_10 = F_63 ( V_148 ) ;
struct V_174 * V_11 = V_10 -> V_11 ;
int V_15 ;
const struct V_141 * V_142 ;
V_15 = F_83 ( V_10 ) ;
if ( V_15 )
return V_15 ;
if ( V_10 -> V_26 & V_152 ) {
V_15 = F_123 ( & V_142 , V_10 -> V_124 ,
& V_10 -> V_18 -> V_67 ) ;
if ( V_15 )
goto V_175;
V_10 -> V_110 = V_142 -> V_20 ;
V_10 -> V_111 = V_142 -> V_146 ;
V_15 = F_85 ( V_10 ) ;
F_101 ( V_142 ) ;
if ( V_15 )
goto V_175;
} else {
F_84 ( V_10 ) ;
return - V_123 ;
}
F_124 ( 100 ) ;
V_15 = F_125 ( V_11 ) ;
if ( V_15 )
goto V_175;
return 0 ;
V_175:
F_84 ( V_10 ) ;
return V_15 ;
}
int F_126 ( void )
{
return F_127 ( & V_176 ) ;
}
void F_128 ( void )
{
F_129 ( & V_176 ) ;
}

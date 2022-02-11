static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1000 ; V_3 > 0 ; V_3 -- ) {
if ( F_2 ( V_2 , V_4 ) & V_5 )
break;
F_3 ( 1 ) ;
}
if ( V_3 <= 0 )
F_4 ( V_2 -> V_6 , L_1 ,
F_2 ( V_2 , V_4 ) ) ;
F_5 ( V_2 , V_4 , 0 ) ;
for ( V_3 = 1000 ; V_3 > 0 ; V_3 -- ) {
if ( F_2 ( V_2 , V_4 ) == 0 )
break;
F_3 ( 1 ) ;
}
if ( V_3 <= 0 )
F_4 ( V_2 -> V_6 , L_2 ,
F_2 ( V_2 , V_4 ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
V_2 -> V_8 . V_9 = V_2 -> V_10 . V_9 ;
V_2 -> V_8 . V_11 = ( V_12 * ) V_2 -> V_10 . V_13 ;
F_8 ( V_2 , V_14 , ( V_15 ) V_2 -> V_8 . V_9 ) ;
F_8 ( V_2 , V_16 , F_9 ( V_2 -> V_8 . V_9 ) ) ;
F_10 ( V_2 , V_17 , 0x02 ) ;
F_5 ( V_2 , V_18 , 0 ) ;
F_5 ( V_2 , V_4 , V_5 ) ;
if ( ! V_2 -> V_19 )
F_1 ( V_2 ) ;
F_10 ( V_2 , V_20 , V_21 ) ;
V_2 -> V_22 . V_9 = V_2 -> V_10 . V_9 + 2048 ;
V_2 -> V_22 . V_11 = ( V_12 * ) ( V_2 -> V_10 . V_13 + 2048 ) ;
V_2 -> V_22 . V_23 = V_2 -> V_22 . V_24 = 0 ;
memset ( V_2 -> V_22 . V_25 , 0 , sizeof( V_2 -> V_22 . V_25 ) ) ;
F_8 ( V_2 , V_26 , ( V_15 ) V_2 -> V_22 . V_9 ) ;
F_8 ( V_2 , V_27 , F_9 ( V_2 -> V_22 . V_9 ) ) ;
F_10 ( V_2 , V_28 , 0x02 ) ;
F_5 ( V_2 , V_29 , V_30 ) ;
F_5 ( V_2 , V_31 , 1 ) ;
F_10 ( V_2 , V_32 , V_33 | V_34 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_32 ) & V_33 )
&& F_15 ( V_35 , V_3 ) )
F_3 ( 10 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_20 ) & V_21 )
&& F_15 ( V_35 , V_3 ) )
F_3 ( 10 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
F_10 ( V_2 , V_32 , 0 ) ;
F_10 ( V_2 , V_20 , 0 ) ;
F_12 ( V_2 ) ;
F_17 ( V_2 , V_36 , V_37 , 0 ) ;
F_11 ( & V_2 -> V_7 ) ;
}
static unsigned int F_18 ( V_15 V_38 )
{
unsigned int V_9 = V_38 >> 28 ;
if ( F_19 ( V_9 >= V_39 ) )
V_9 = 0 ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_40 )
{
unsigned int V_9 = F_18 ( V_40 ) ;
unsigned int V_23 , V_24 ;
F_7 ( & V_2 -> V_7 ) ;
V_2 -> V_41 [ F_18 ( V_40 ) ] = V_40 ;
V_23 = F_2 ( V_2 , V_18 ) ;
if ( V_23 == 0xffff ) {
F_11 ( & V_2 -> V_7 ) ;
return - V_42 ;
}
V_23 ++ ;
V_23 %= V_43 ;
V_24 = F_2 ( V_2 , V_4 ) ;
if ( V_23 == V_24 ) {
F_11 ( & V_2 -> V_7 ) ;
return - V_44 ;
}
V_2 -> V_22 . V_25 [ V_9 ] ++ ;
V_2 -> V_8 . V_11 [ V_23 ] = F_21 ( V_40 ) ;
F_5 ( V_2 , V_18 , V_23 ) ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
unsigned int V_24 , V_23 ;
unsigned int V_9 ;
V_15 V_45 , V_46 ;
V_23 = F_2 ( V_2 , V_29 ) ;
if ( V_23 == 0xffff ) {
return;
}
if ( V_23 == V_2 -> V_22 . V_23 )
return;
V_2 -> V_22 . V_23 = V_23 ;
while ( V_2 -> V_22 . V_24 != V_23 ) {
V_2 -> V_22 . V_24 ++ ;
V_2 -> V_22 . V_24 %= V_47 ;
V_24 = V_2 -> V_22 . V_24 << 1 ;
V_46 = F_23 ( V_2 -> V_22 . V_11 [ V_24 + 1 ] ) ;
V_45 = F_23 ( V_2 -> V_22 . V_11 [ V_24 ] ) ;
V_9 = V_46 & 0xf ;
if ( V_9 >= V_39 ) {
F_4 ( V_2 -> V_6 ,
L_3 ,
V_45 , V_46 , V_2 -> V_22 . V_24 , V_23 ) ;
F_24 () ;
} else if ( V_46 & V_48 )
F_25 ( V_2 , V_45 , V_46 ) ;
else if ( V_2 -> V_22 . V_25 [ V_9 ] ) {
V_2 -> V_22 . V_45 [ V_9 ] = V_45 ;
V_2 -> V_22 . V_25 [ V_9 ] -- ;
} else {
F_26 ( V_2 -> V_6 ,
L_4 ,
V_45 , V_46 , V_2 -> V_41 [ V_9 ] ) ;
}
}
}
int F_27 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int * V_45 )
{
unsigned long V_3 ;
unsigned long V_49 ;
V_3 = V_35 + F_13 ( 1000 ) ;
for ( V_49 = 0 ; ; V_49 ++ ) {
F_7 ( & V_2 -> V_7 ) ;
if ( ! V_2 -> V_22 . V_25 [ V_9 ] ) {
if ( V_45 )
* V_45 = V_2 -> V_22 . V_45 [ V_9 ] ;
F_11 ( & V_2 -> V_7 ) ;
return 0 ;
}
F_11 ( & V_2 -> V_7 ) ;
if ( F_28 ( V_35 , V_3 ) )
break;
if ( V_49 > 3000 )
F_29 ( 2 ) ;
else {
F_3 ( 10 ) ;
F_30 () ;
}
}
return - V_42 ;
}
void F_31 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_17 ( V_2 , V_36 , V_50 , 0 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ( F_14 ( V_2 , V_36 ) & V_50 ) &&
F_15 ( V_35 , V_3 ) )
F_32 ( 500 , 1000 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_34 ( V_2 , V_36 , 0 , V_50 ) ;
V_3 = V_35 + F_13 ( 100 ) ;
while ( ! F_14 ( V_2 , V_36 ) && F_15 ( V_35 , V_3 ) )
F_32 ( 500 , 1000 ) ;
}
static int F_35 ( struct V_1 * V_2 , bool V_51 )
{
if ( ! V_51 )
goto V_52;
F_5 ( V_2 , V_53 , V_54 ) ;
F_31 ( V_2 ) ;
F_32 ( 500 , 1000 ) ;
F_33 ( V_2 ) ;
F_32 ( 1000 , 1200 ) ;
V_52:
if ( ! F_14 ( V_2 , V_36 ) ) {
F_36 ( V_2 -> V_6 , L_5 ) ;
return - V_55 ;
}
F_17 ( V_2 , V_36 , 0 , V_37 ) ;
if ( ! V_2 -> V_56 ) {
V_2 -> V_56 = F_2 ( V_2 , V_53 ) ;
F_36 ( V_2 -> V_6 , L_6 , V_2 -> V_56 ) ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_57 , 0 , V_58 | V_59 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
F_39 (azx_dev, &bus->stream_list, list)
F_40 ( V_61 , V_62 , V_63 , 0 ) ;
F_10 ( V_2 , V_57 , 0 ) ;
F_17 ( V_2 , V_57 , V_58 | V_59 , 0 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
F_39 (azx_dev, &bus->stream_list, list)
F_42 ( V_61 , V_64 , V_63 ) ;
F_5 ( V_2 , V_53 , V_54 ) ;
F_10 ( V_2 , V_65 , V_66 ) ;
F_8 ( V_2 , V_67 , V_58 | V_68 ) ;
}
bool F_43 ( struct V_1 * V_2 , bool V_51 )
{
if ( V_2 -> V_69 )
return false ;
F_35 ( V_2 , V_51 ) ;
F_41 ( V_2 ) ;
F_37 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_70 && V_2 -> V_71 . V_9 ) {
F_8 ( V_2 , V_72 , ( V_15 ) V_2 -> V_71 . V_9 ) ;
F_8 ( V_2 , V_73 , F_9 ( V_2 -> V_71 . V_9 ) ) ;
}
V_2 -> V_69 = true ;
return true ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_69 )
return;
F_38 ( V_2 ) ;
F_41 ( V_2 ) ;
F_16 ( V_2 ) ;
if ( V_2 -> V_71 . V_9 ) {
F_8 ( V_2 , V_72 , 0 ) ;
F_8 ( V_2 , V_73 , 0 ) ;
}
V_2 -> V_69 = false ;
}
int F_45 ( struct V_1 * V_2 , unsigned int V_74 ,
void (* F_46)( struct V_1 * ,
struct V_60 * ) )
{
struct V_60 * V_61 ;
T_1 V_75 ;
int V_76 = 0 ;
F_39 (azx_dev, &bus->stream_list, list) {
if ( V_74 & V_61 -> V_77 ) {
V_75 = F_47 ( V_61 , V_64 ) ;
F_42 ( V_61 , V_64 , V_63 ) ;
V_76 |= 1 << V_61 -> V_78 ;
if ( ! V_61 -> V_79 || ! V_61 -> V_80 ||
! ( V_75 & V_81 ) )
continue;
if ( F_46 )
F_46 ( V_2 , V_61 ) ;
}
}
return V_76 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_60 * V_82 ;
int V_83 = 0 ;
int V_84 ;
F_39 (s, &bus->stream_list, list) {
V_84 = V_2 -> V_85 -> V_86 ( V_2 , V_87 ,
V_88 , & V_82 -> V_89 ) ;
V_83 ++ ;
if ( V_84 < 0 )
return - V_90 ;
}
if ( F_49 ( ! V_83 ) )
return - V_91 ;
V_84 = V_2 -> V_85 -> V_86 ( V_2 , V_87 ,
V_83 * 8 , & V_2 -> V_71 ) ;
if ( V_84 < 0 )
return - V_90 ;
F_39 (s, &bus->stream_list, list)
V_82 -> V_71 = ( V_12 * ) ( V_2 -> V_71 . V_13 + V_82 -> V_78 * 8 ) ;
return V_2 -> V_85 -> V_86 ( V_2 , V_87 ,
V_92 , & V_2 -> V_10 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_60 * V_82 ;
F_39 (s, &bus->stream_list, list) {
if ( V_82 -> V_89 . V_13 )
V_2 -> V_85 -> V_93 ( V_2 , & V_82 -> V_89 ) ;
}
if ( V_2 -> V_10 . V_13 )
V_2 -> V_85 -> V_93 ( V_2 , & V_2 -> V_10 ) ;
if ( V_2 -> V_71 . V_13 )
V_2 -> V_85 -> V_93 ( V_2 , & V_2 -> V_71 ) ;
}

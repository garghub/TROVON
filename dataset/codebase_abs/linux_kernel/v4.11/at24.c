static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int * V_4 )
{
unsigned V_5 ;
if ( V_3 -> V_6 . V_7 & V_8 ) {
V_5 = * V_4 >> 16 ;
* V_4 &= 0xffff ;
} else {
V_5 = * V_4 >> 8 ;
* V_4 &= 0xff ;
}
return V_3 -> V_9 [ V_5 ] ;
}
static T_1 F_2 ( struct V_2 * V_3 , char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
struct V_1 * V_9 ;
int V_14 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_15 )
V_11 = V_15 ;
if ( V_11 > V_16 )
V_11 = V_16 ;
F_3 (timeout, read_time) {
V_14 = F_4 ( V_9 ,
V_4 ,
V_11 , V_10 ) ;
F_5 ( & V_9 -> V_17 , L_1 ,
V_11 , V_4 , V_14 , V_18 ) ;
if ( V_14 == V_11 )
return V_11 ;
}
return - V_19 ;
}
static T_1 F_6 ( struct V_2 * V_3 , char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
struct V_1 * V_9 ;
struct V_20 V_21 [ 2 ] ;
int V_14 , V_5 ;
T_3 V_22 [ 2 ] ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
V_9 = F_1 ( V_3 , & V_4 ) ;
if ( V_11 > V_15 )
V_11 = V_15 ;
V_5 = 0 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_22 [ V_5 ++ ] = V_4 >> 8 ;
V_22 [ V_5 ++ ] = V_4 ;
V_21 [ 0 ] . V_23 = V_9 -> V_23 ;
V_21 [ 0 ] . V_10 = V_22 ;
V_21 [ 0 ] . V_24 = V_5 ;
V_21 [ 1 ] . V_23 = V_9 -> V_23 ;
V_21 [ 1 ] . V_7 = V_25 ;
V_21 [ 1 ] . V_10 = V_10 ;
V_21 [ 1 ] . V_24 = V_11 ;
F_3 (timeout, read_time) {
V_14 = F_7 ( V_9 -> V_26 , V_21 , 2 ) ;
if ( V_14 == 2 )
V_14 = V_11 ;
F_5 ( & V_9 -> V_17 , L_1 ,
V_11 , V_4 , V_14 , V_18 ) ;
if ( V_14 == V_11 )
return V_11 ;
}
return - V_19 ;
}
static T_1 F_8 ( struct V_2 * V_3 , char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
struct V_1 * V_9 ;
struct V_20 V_21 [ 2 ] ;
T_3 V_27 [ 2 ] ;
int V_14 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
V_21 [ 0 ] . V_23 = V_9 -> V_23 ;
V_21 [ 0 ] . V_10 = V_27 ;
if ( V_3 -> V_6 . V_7 & V_8 ) {
V_27 [ 0 ] = 0x08 ;
V_27 [ 1 ] = V_4 ;
V_21 [ 0 ] . V_24 = 2 ;
} else {
V_27 [ 0 ] = 0x80 + V_4 ;
V_21 [ 0 ] . V_24 = 1 ;
}
V_21 [ 1 ] . V_23 = V_9 -> V_23 ;
V_21 [ 1 ] . V_7 = V_25 ;
V_21 [ 1 ] . V_10 = V_10 ;
V_21 [ 1 ] . V_24 = V_11 ;
F_3 (timeout, read_time) {
V_14 = F_7 ( V_9 -> V_26 , V_21 , 2 ) ;
if ( V_14 == 2 )
return V_11 ;
}
return - V_19 ;
}
static T_1 F_9 ( struct V_2 * V_3 , char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
struct V_1 * V_9 ;
struct V_20 V_21 [ 2 ] ;
T_3 V_27 [ 2 ] ;
int V_14 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
V_21 [ 0 ] . V_23 = V_9 -> V_23 ;
V_21 [ 0 ] . V_10 = V_27 ;
V_27 [ 0 ] = 0x90 + V_4 ;
V_21 [ 0 ] . V_24 = 1 ;
V_21 [ 1 ] . V_23 = V_9 -> V_23 ;
V_21 [ 1 ] . V_7 = V_25 ;
V_21 [ 1 ] . V_10 = V_10 ;
V_21 [ 1 ] . V_24 = V_11 ;
F_3 (timeout, read_time) {
V_14 = F_7 ( V_9 -> V_26 , V_21 , 2 ) ;
if ( V_14 == 2 )
return V_11 ;
}
return - V_19 ;
}
static T_2 F_10 ( struct V_2 * V_3 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned V_28 ;
if ( V_11 > V_3 -> V_29 )
V_11 = V_3 -> V_29 ;
V_28 = F_11 ( V_4 + 1 , V_3 -> V_6 . V_30 ) ;
if ( V_4 + V_11 > V_28 )
V_11 = V_28 - V_4 ;
return V_11 ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
const char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_31 ;
struct V_1 * V_9 ;
T_1 V_14 = 0 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
V_11 = F_10 ( V_3 , V_4 , V_11 ) ;
F_3 (timeout, write_time) {
V_14 = F_13 ( V_9 ,
V_4 , V_11 , V_10 ) ;
if ( V_14 == 0 )
V_14 = V_11 ;
F_5 ( & V_9 -> V_17 , L_2 ,
V_11 , V_4 , V_14 , V_18 ) ;
if ( V_14 == V_11 )
return V_11 ;
}
return - V_19 ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
const char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_31 ;
struct V_1 * V_9 ;
T_1 V_14 = 0 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
F_3 (timeout, write_time) {
V_14 = F_15 ( V_9 , V_4 , V_10 [ 0 ] ) ;
if ( V_14 == 0 )
V_14 = V_11 ;
F_5 ( & V_9 -> V_17 , L_2 ,
V_11 , V_4 , V_14 , V_18 ) ;
if ( V_14 == V_11 )
return V_11 ;
}
return - V_19 ;
}
static T_1 F_16 ( struct V_2 * V_3 , const char * V_10 ,
unsigned int V_4 , T_2 V_11 )
{
unsigned long V_12 , V_31 ;
struct V_1 * V_9 ;
struct V_20 V_21 ;
T_1 V_14 = 0 ;
int V_5 = 0 ;
V_9 = F_1 ( V_3 , & V_4 ) ;
V_11 = F_10 ( V_3 , V_4 , V_11 ) ;
V_21 . V_23 = V_9 -> V_23 ;
V_21 . V_7 = 0 ;
V_21 . V_10 = V_3 -> V_32 ;
if ( V_3 -> V_6 . V_7 & V_8 )
V_21 . V_10 [ V_5 ++ ] = V_4 >> 8 ;
V_21 . V_10 [ V_5 ++ ] = V_4 ;
memcpy ( & V_21 . V_10 [ V_5 ] , V_10 , V_11 ) ;
V_21 . V_24 = V_5 + V_11 ;
F_3 (timeout, write_time) {
V_14 = F_7 ( V_9 -> V_26 , & V_21 , 1 ) ;
if ( V_14 == 1 )
V_14 = V_11 ;
F_5 ( & V_9 -> V_17 , L_2 ,
V_11 , V_4 , V_14 , V_18 ) ;
if ( V_14 == V_11 )
return V_11 ;
}
return - V_19 ;
}
static int F_17 ( void * V_33 , unsigned int V_34 , void * V_35 , T_2 V_11 )
{
struct V_2 * V_3 = V_33 ;
char * V_10 = V_35 ;
if ( F_18 ( ! V_11 ) )
return V_11 ;
F_19 ( & V_3 -> V_36 ) ;
while ( V_11 ) {
int V_14 ;
V_14 = V_3 -> V_37 ( V_3 , V_10 , V_34 , V_11 ) ;
if ( V_14 < 0 ) {
F_20 ( & V_3 -> V_36 ) ;
return V_14 ;
}
V_10 += V_14 ;
V_34 += V_14 ;
V_11 -= V_14 ;
}
F_20 ( & V_3 -> V_36 ) ;
return 0 ;
}
static int F_21 ( void * V_33 , unsigned int V_34 , void * V_35 , T_2 V_11 )
{
struct V_2 * V_3 = V_33 ;
char * V_10 = V_35 ;
if ( F_18 ( ! V_11 ) )
return - V_38 ;
F_19 ( & V_3 -> V_36 ) ;
while ( V_11 ) {
int V_14 ;
V_14 = V_3 -> V_39 ( V_3 , V_10 , V_34 , V_11 ) ;
if ( V_14 < 0 ) {
F_20 ( & V_3 -> V_36 ) ;
return V_14 ;
}
V_10 += V_14 ;
V_34 += V_14 ;
V_11 -= V_14 ;
}
F_20 ( & V_3 -> V_36 ) ;
return 0 ;
}
static void F_22 ( struct V_40 * V_17 , struct V_41 * V_6 )
{
int V_42 ;
T_4 V_35 ;
if ( F_23 ( V_17 , L_3 ) )
V_6 -> V_7 |= V_43 ;
V_42 = F_24 ( V_17 , L_4 , & V_35 ) ;
if ( ! V_42 ) {
V_6 -> V_30 = V_35 ;
} else {
V_6 -> V_30 = 1 ;
}
}
static int F_25 ( struct V_1 * V_9 , const struct V_44 * V_45 )
{
struct V_41 V_6 ;
T_5 V_46 = 0 ;
bool V_47 ;
int V_48 = 0 ;
int V_49 = 0 ;
struct V_2 * V_3 ;
int V_42 ;
unsigned V_5 , V_50 ;
T_3 V_51 ;
if ( V_9 -> V_17 . V_52 ) {
V_6 = * (struct V_41 * ) V_9 -> V_17 . V_52 ;
} else {
if ( V_45 ) {
V_46 = V_45 -> V_53 ;
} else {
const struct V_54 * V_55 ;
V_55 = F_26 ( V_56 , & V_9 -> V_17 ) ;
if ( V_55 )
V_46 = V_55 -> V_53 ;
}
if ( ! V_46 )
return - V_57 ;
V_6 . V_58 = F_27 ( V_46 & F_28 ( V_59 ) ) ;
V_46 >>= V_59 ;
V_6 . V_7 = V_46 & F_28 ( V_60 ) ;
F_22 ( & V_9 -> V_17 , & V_6 ) ;
V_6 . V_61 = NULL ;
V_6 . V_62 = NULL ;
}
if ( ! F_29 ( V_6 . V_58 ) )
F_30 ( & V_9 -> V_17 ,
L_5 ) ;
if ( ! V_6 . V_30 ) {
F_31 ( & V_9 -> V_17 , L_6 ) ;
return - V_38 ;
}
if ( ! F_29 ( V_6 . V_30 ) )
F_30 ( & V_9 -> V_17 ,
L_7 ) ;
if ( ! F_32 ( V_9 -> V_26 , V_63 ) ) {
if ( V_6 . V_7 & V_8 )
return - V_64 ;
if ( F_32 ( V_9 -> V_26 ,
V_65 ) ) {
V_48 = V_66 ;
} else if ( F_32 ( V_9 -> V_26 ,
V_67 ) ) {
V_48 = V_68 ;
} else if ( F_32 ( V_9 -> V_26 ,
V_69 ) ) {
V_48 = V_70 ;
} else {
return - V_64 ;
}
if ( F_32 ( V_9 -> V_26 ,
V_71 ) ) {
V_49 = V_66 ;
} else if ( F_32 ( V_9 -> V_26 ,
V_72 ) ) {
V_49 = V_70 ;
V_6 . V_30 = 1 ;
}
}
if ( V_6 . V_7 & V_73 )
V_50 = 8 ;
else
V_50 = F_33 ( V_6 . V_58 ,
( V_6 . V_7 & V_8 ) ? 65536 : 256 ) ;
V_3 = F_34 ( & V_9 -> V_17 , sizeof( struct V_2 ) +
V_50 * sizeof( struct V_1 * ) , V_74 ) ;
if ( ! V_3 )
return - V_75 ;
F_35 ( & V_3 -> V_36 ) ;
V_3 -> V_48 = V_48 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_50 = V_50 ;
if ( ( V_6 . V_7 & V_76 ) && ( V_6 . V_7 & V_77 ) ) {
F_31 ( & V_9 -> V_17 ,
L_8 ) ;
return - V_38 ;
}
if ( V_6 . V_7 & V_76 ) {
V_3 -> V_37 = F_8 ;
} else if ( V_6 . V_7 & V_77 ) {
V_3 -> V_37 = F_9 ;
} else {
V_3 -> V_37 = V_3 -> V_48 ? F_2
: F_6 ;
}
if ( V_3 -> V_48 ) {
if ( V_3 -> V_49 == V_66 )
V_3 -> V_39 = F_12 ;
else
V_3 -> V_39 = F_14 ;
} else {
V_3 -> V_39 = F_16 ;
}
V_47 = ! ( V_6 . V_7 & V_43 ) ;
if ( V_47 ) {
if ( ! V_48 || V_49 ) {
unsigned V_29 = V_6 . V_30 ;
if ( V_29 > V_15 )
V_29 = V_15 ;
if ( V_48 && V_29 > V_16 )
V_29 = V_16 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_32 = F_34 ( & V_9 -> V_17 ,
V_29 + 2 , V_74 ) ;
if ( ! V_3 -> V_32 )
return - V_75 ;
} else {
F_30 ( & V_9 -> V_17 ,
L_9 ) ;
}
}
V_3 -> V_9 [ 0 ] = V_9 ;
for ( V_5 = 1 ; V_5 < V_50 ; V_5 ++ ) {
V_3 -> V_9 [ V_5 ] = F_36 ( V_9 -> V_26 ,
V_9 -> V_23 + V_5 ) ;
if ( ! V_3 -> V_9 [ V_5 ] ) {
F_31 ( & V_9 -> V_17 , L_10 ,
V_9 -> V_23 + V_5 ) ;
V_42 = - V_78 ;
goto V_79;
}
}
F_37 ( V_9 , V_3 ) ;
V_42 = F_17 ( V_3 , 0 , & V_51 , 1 ) ;
if ( V_42 ) {
V_42 = - V_57 ;
goto V_79;
}
V_3 -> V_80 . V_81 = F_38 ( & V_9 -> V_17 ) ;
V_3 -> V_80 . V_17 = & V_9 -> V_17 ;
V_3 -> V_80 . V_82 = ! V_47 ;
V_3 -> V_80 . V_83 = true ;
V_3 -> V_80 . V_84 = V_85 ;
V_3 -> V_80 . V_86 = true ;
V_3 -> V_80 . V_87 = & V_9 -> V_17 ;
V_3 -> V_80 . V_88 = F_17 ;
V_3 -> V_80 . V_89 = F_21 ;
V_3 -> V_80 . V_33 = V_3 ;
V_3 -> V_80 . V_90 = 4 ;
V_3 -> V_80 . V_91 = 1 ;
V_3 -> V_80 . V_92 = V_6 . V_58 ;
V_3 -> V_93 = F_39 ( & V_3 -> V_80 ) ;
if ( F_40 ( V_3 -> V_93 ) ) {
V_42 = F_41 ( V_3 -> V_93 ) ;
goto V_79;
}
F_42 ( & V_9 -> V_17 , L_11 ,
V_6 . V_58 , V_9 -> V_81 ,
V_47 ? L_12 : L_3 , V_3 -> V_29 ) ;
if ( V_48 == V_68 ||
V_48 == V_70 ) {
F_43 ( & V_9 -> V_17 , L_13
L_14 , V_48 ==
V_68 ? L_15 : L_16 ) ;
}
if ( V_6 . V_61 )
V_6 . V_61 ( V_3 -> V_93 , V_6 . V_62 ) ;
return 0 ;
V_79:
for ( V_5 = 1 ; V_5 < V_50 ; V_5 ++ )
if ( V_3 -> V_9 [ V_5 ] )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return V_42 ;
}
static int F_45 ( struct V_1 * V_9 )
{
struct V_2 * V_3 ;
int V_5 ;
V_3 = F_46 ( V_9 ) ;
F_47 ( V_3 -> V_93 ) ;
for ( V_5 = 1 ; V_5 < V_3 -> V_50 ; V_5 ++ )
F_44 ( V_3 -> V_9 [ V_5 ] ) ;
return 0 ;
}
static int T_6 F_48 ( void )
{
if ( ! V_15 ) {
F_49 ( L_17 ) ;
return - V_38 ;
}
V_15 = F_50 ( V_15 ) ;
return F_51 ( & V_94 ) ;
}
static void T_7 F_52 ( void )
{
F_53 ( & V_94 ) ;
}

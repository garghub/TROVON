static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_5 ;
F_4 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] . V_8 == 0 )
continue;
F_5 ( V_2 -> V_9 , & V_2 -> V_7 [ V_5 ] ) ;
}
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
int V_10 = 0 ;
struct V_11 * V_12 = V_2 -> V_13 -> V_7 ;
F_4 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_12 [ V_5 ] . V_8 == 0 )
continue;
V_2 -> V_7 [ V_5 ] . V_8 = V_12 [ V_5 ] . V_8 ;
V_10 = F_8 ( V_2 -> V_9 , & V_2 -> V_7 [ V_5 ] ) ;
if ( V_10 ) {
F_9 ( V_2 ,
L_1 , V_5 ) ;
goto V_14;
}
if ( V_5 == V_15 ||
V_5 == V_16 ||
V_5 == V_17 ) {
void * V_18 ;
V_18 = F_10 ( V_2 -> V_19 . V_20 ,
V_12 [ V_5 ] . V_21 ) ;
memcpy ( V_2 -> V_7 [ V_5 ] . V_22 , V_18 , V_12 [ V_5 ] . V_8 ) ;
}
V_12 [ V_5 ] . V_23 = V_2 -> V_7 [ V_5 ] . V_24 ;
F_11 ( V_2 ,
L_2 ,
V_5 , V_2 -> V_7 [ V_5 ] . V_22 ,
& V_2 -> V_7 [ V_5 ] . V_24 ,
V_2 -> V_7 [ V_5 ] . V_8 ) ;
}
F_6 ( V_2 ) ;
return V_10 ;
V_14:
F_3 ( V_2 ) ;
return V_10 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
unsigned int V_25 = 0 ;
struct V_26 * V_9 = (struct V_26 * ) V_2 -> V_9 ;
if ( ! F_13 ( V_9 , V_27 ,
V_28 ) ) {
V_25 = V_9 -> V_25 ;
F_11 ( V_2 , L_3 , V_25 ) ;
}
return V_25 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
unsigned int V_32 ;
T_1 V_33 ;
T_1 V_34 ;
unsigned int V_35 ;
T_2 V_36 [ V_37 ] ;
T_1 V_38 ;
V_33 = F_1 ( V_2 , V_39 ) ;
V_34 = F_1 ( V_2 , V_40 ) ;
V_32 = ! V_2 -> V_19 . V_41 ;
V_38 = ( V_34 << 5 ) | 0x10 | V_32 ;
V_36 [ 0 ] = V_38 & 0xff ;
V_36 [ 1 ] = ( V_38 >> 8 ) & 0xff ;
V_36 [ 2 ] = ( V_38 >> 16 ) & 0xff ;
if ( V_32 == 0 ) {
V_35 = V_37 ;
V_36 [ 3 ] = 0x9d ;
V_36 [ 4 ] = 0x01 ;
V_36 [ 5 ] = 0x2a ;
V_36 [ 6 ] = V_2 -> V_13 -> V_42 . V_43 ;
V_36 [ 7 ] = V_2 -> V_13 -> V_42 . V_43 >> 8 ;
V_36 [ 8 ] = V_2 -> V_13 -> V_42 . V_44 ;
V_36 [ 9 ] = V_2 -> V_13 -> V_42 . V_44 >> 8 ;
} else {
V_35 = 3 ;
}
if ( V_30 -> V_8 < V_34 + V_33 + V_35 ) {
F_9 ( V_2 , L_4 ,
V_30 -> V_8 ) ;
return - V_45 ;
}
memmove ( V_30 -> V_22 + V_34 + V_35 ,
V_30 -> V_22 , V_33 ) ;
memcpy ( V_30 -> V_22 + V_35 ,
V_2 -> V_7 [ V_46 ] . V_22 ,
V_34 ) ;
memcpy ( V_30 -> V_22 , V_36 , V_35 ) ;
* V_31 = V_33 + V_34 + V_35 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_29 * V_30 ,
unsigned int * V_31 )
{
int V_10 = 0 ;
unsigned int V_25 ;
F_11 ( V_2 , L_5 , V_2 -> V_49 ) ;
V_10 = F_16 ( & V_2 -> V_19 , 0 , V_48 , V_30 , V_31 ) ;
if ( V_10 )
return V_10 ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 != V_50 ) {
F_9 ( V_2 , L_6 , V_25 ) ;
return - V_51 ;
}
if ( F_14 ( V_2 , V_30 , V_31 ) ) {
F_9 ( V_2 , L_7 ) ;
return - V_45 ;
}
V_2 -> V_49 ++ ;
F_11 ( V_2 , L_8 , * V_31 ,
V_2 -> V_19 . V_41 ) ;
return V_10 ;
}
static int F_17 ( struct V_26 * V_9 , unsigned long * V_52 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_19 . V_9 = V_9 ;
V_2 -> V_19 . V_20 = V_9 -> V_20 -> V_55 ;
V_2 -> V_19 . V_56 = V_57 ;
V_2 -> V_4 = F_19 ( V_2 -> V_9 , V_58 ) ;
F_4 ( V_2 ) ;
V_10 = F_20 ( & V_2 -> V_19 ) ;
V_2 -> V_13 = (struct V_59 * ) V_2 -> V_19 . V_13 ;
F_6 ( V_2 ) ;
if ( V_10 )
F_21 ( V_2 ) ;
else
( * V_52 ) = ( unsigned long ) V_2 ;
return V_10 ;
}
static int F_22 ( unsigned long V_52 ,
enum V_60 V_61 ,
struct V_47 * V_48 ,
struct V_29 * V_30 ,
struct V_62 * V_63 )
{
int V_10 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
struct V_26 * V_9 = V_2 -> V_9 ;
F_4 ( V_2 ) ;
F_23 ( V_9 -> V_20 -> V_64 ) ;
switch ( V_61 ) {
case V_65 :
V_10 = F_15 ( V_2 , V_48 , V_30 ,
& V_63 -> V_31 ) ;
if ( V_10 )
goto V_66;
V_63 -> V_41 = V_2 -> V_19 . V_41 ;
break;
default:
F_9 ( V_2 , L_9 , V_61 ) ;
V_10 = - V_45 ;
break;
}
V_66:
F_24 ( V_9 -> V_20 -> V_64 ) ;
F_6 ( V_2 ) ;
return V_10 ;
}
static int F_25 ( unsigned long V_52 ,
enum V_67 type ,
struct V_68 * V_69 )
{
int V_10 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_11 ( V_2 , L_10 , type ) ;
switch ( type ) {
case V_70 :
V_2 -> V_13 -> V_42 . V_71 = V_69 -> V_72 ;
V_2 -> V_13 -> V_42 . V_73 = V_69 -> V_73 ;
V_2 -> V_13 -> V_42 . V_43 = V_69 -> V_74 ;
V_2 -> V_13 -> V_42 . V_44 = V_69 -> V_75 ;
V_2 -> V_13 -> V_42 . V_76 = V_69 -> V_77 ;
V_2 -> V_13 -> V_42 . V_78 = V_69 -> V_79 ;
V_2 -> V_13 -> V_42 . V_80 = V_69 -> V_80 ;
V_2 -> V_13 -> V_42 . V_81 = V_69 -> V_82 ;
V_2 -> V_13 -> V_42 . V_83 = V_2 -> V_83 ;
V_10 = F_26 ( & V_2 -> V_19 , type , V_69 ) ;
if ( V_10 )
break;
if ( V_2 -> V_84 ) {
F_3 ( V_2 ) ;
V_2 -> V_84 = false ;
}
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
break;
V_2 -> V_84 = true ;
break;
case V_85 :
V_2 -> V_83 = 1 ;
F_11 ( V_2 , L_11 ) ;
break;
default:
V_10 = F_26 ( & V_2 -> V_19 , type , V_69 ) ;
break;
}
F_6 ( V_2 ) ;
return V_10 ;
}
static int F_27 ( unsigned long V_52 )
{
int V_10 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_4 ( V_2 ) ;
V_10 = F_28 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_84 )
F_3 ( V_2 ) ;
F_6 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_10 ;
}
const struct V_86 * F_29 ( void )
{
return & V_87 ;
}

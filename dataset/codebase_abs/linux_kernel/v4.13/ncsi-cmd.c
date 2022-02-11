T_1 F_1 ( unsigned char * V_1 , int V_2 )
{
T_1 V_3 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 += 2 )
V_3 += ( ( ( T_1 ) V_1 [ V_4 ] << 8 ) | V_1 [ V_4 + 1 ] ) ;
V_3 = ( ~ V_3 + 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
T_1 V_3 ;
T_2 * V_9 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = V_8 -> V_14 ;
V_6 -> type = V_8 -> type ;
V_6 -> V_15 = F_3 ( V_8 -> V_16 ,
V_8 -> V_15 ) ;
V_6 -> V_17 = F_4 ( V_8 -> V_18 ) ;
V_6 -> V_19 [ 0 ] = 0 ;
V_6 -> V_19 [ 1 ] = 0 ;
V_3 = F_1 ( ( unsigned char * ) V_6 ,
sizeof( * V_6 ) + V_8 -> V_18 ) ;
V_9 = ( T_2 * ) ( ( void * ) V_6 + sizeof( struct V_5 ) +
V_8 -> V_18 ) ;
* V_9 = F_5 ( V_3 ) ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_25 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_26 = V_8 -> V_27 [ 0 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_28 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_29 = V_8 -> V_27 [ 0 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_30 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_31 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_10 = V_8 -> V_27 [ 0 ] ;
V_23 -> V_32 = F_5 ( V_8 -> V_33 [ 1 ] ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_34 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_32 = F_5 ( V_8 -> V_33 [ 0 ] ) ;
V_23 -> V_35 = F_5 ( V_8 -> V_33 [ 1 ] ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_36 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_37 = F_4 ( V_8 -> V_38 [ 0 ] ) ;
V_23 -> V_39 = V_8 -> V_27 [ 2 ] ;
V_23 -> V_40 = V_8 -> V_27 [ 3 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_41 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_32 = V_8 -> V_27 [ 0 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_42 * V_23 ;
int V_4 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ )
V_23 -> V_43 [ V_4 ] = V_8 -> V_27 [ V_4 ] ;
V_23 -> V_39 = V_8 -> V_27 [ 6 ] ;
V_23 -> V_44 = V_8 -> V_27 [ 7 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_45 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_32 = F_5 ( V_8 -> V_33 [ 0 ] ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_46 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_32 = F_5 ( V_8 -> V_33 [ 0 ] ) ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_7 * V_8 )
{
struct V_47 * V_23 ;
V_23 = F_7 ( V_21 , sizeof( * V_23 ) ) ;
V_23 -> V_32 = V_8 -> V_27 [ 0 ] ;
F_2 ( & V_23 -> V_23 . V_24 , V_8 ) ;
return 0 ;
}
static struct V_48 * F_19 ( struct V_7 * V_8 )
{
struct V_49 * V_50 = V_8 -> V_50 ;
struct V_51 * V_52 = & V_50 -> V_53 ;
struct V_54 * V_55 = V_52 -> V_55 ;
int V_56 = F_20 ( V_55 ) ;
int V_57 = V_55 -> V_58 ;
int V_2 = V_56 + V_57 ;
struct V_20 * V_21 ;
struct V_48 * V_59 ;
V_59 = F_21 ( V_50 , V_8 -> V_60 ) ;
if ( ! V_59 )
return NULL ;
V_2 += sizeof( struct V_61 ) + 4 ;
if ( V_8 -> V_18 < 26 )
V_2 += 26 ;
else
V_2 += V_8 -> V_18 ;
V_21 = F_22 ( V_2 , V_62 ) ;
if ( ! V_21 ) {
F_23 ( V_59 ) ;
return NULL ;
}
V_59 -> V_23 = V_21 ;
F_24 ( V_21 , V_56 ) ;
F_25 ( V_21 ) ;
V_21 -> V_55 = V_55 ;
V_21 -> V_63 = F_4 ( V_64 ) ;
return V_59 ;
}
int F_26 ( struct V_7 * V_8 )
{
struct V_48 * V_59 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = NULL ;
int V_4 , V_69 ;
for ( V_4 = 0 ; V_4 < F_27 ( V_70 ) ; V_4 ++ ) {
if ( V_70 [ V_4 ] . type == V_8 -> type ) {
if ( V_70 [ V_4 ] . V_71 )
V_68 = & V_70 [ V_4 ] ;
else
V_68 = NULL ;
break;
}
}
if ( ! V_68 ) {
F_28 ( V_8 -> V_50 -> V_53 . V_55 ,
L_1 , V_8 -> type ) ;
return - V_72 ;
}
V_8 -> V_18 = V_68 -> V_18 ;
V_59 = F_19 ( V_8 ) ;
if ( ! V_59 )
return - V_73 ;
V_8 -> V_14 = V_59 -> V_14 ;
V_69 = V_68 -> V_71 ( V_59 -> V_23 , V_8 ) ;
if ( V_69 ) {
F_23 ( V_59 ) ;
return V_69 ;
}
V_66 = F_29 ( V_59 -> V_23 , sizeof( * V_66 ) ) ;
V_66 -> V_74 = F_4 ( V_64 ) ;
F_30 ( V_66 -> V_75 ) ;
F_30 ( V_66 -> V_76 ) ;
V_59 -> V_77 = true ;
F_31 ( & V_59 -> V_78 , V_79 + 1 * V_80 ) ;
F_32 ( V_59 -> V_23 ) ;
V_69 = F_33 ( V_59 -> V_23 ) ;
if ( V_69 < 0 ) {
F_23 ( V_59 ) ;
return V_69 ;
}
return 0 ;
}

static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 [ V_8 -> V_10 ] )
return NULL ;
return V_6 -> V_9 [ V_8 -> V_10 ] -> V_5 -> V_11 ;
}
int F_4 ( struct V_7 * V_8 ,
struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_19 * V_20 ;
int V_21 ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
V_21 = F_6 ( V_8 , V_13 , V_15 ) ;
if ( V_21 )
return V_21 ;
F_7 ( V_8 , V_20 ,
V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_12 * V_13 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_23 * V_9 = F_9 ( V_8 ) ;
int (* F_10)( struct V_7 * V_8 ,
struct V_12 * V_13 ,
struct V_14 * V_15 );
struct V_14 V_15 ;
int V_21 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
if ( ! V_6 -> V_24 )
F_10 = F_4 ;
else
F_10 = V_6 -> V_24 -> F_10 ;
if ( F_10 ) {
V_21 = F_10 ( V_8 , V_13 , & V_15 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_9 , & V_15 ) ;
if ( V_21 )
return V_21 ;
}
return F_12 ( V_8 , F_13 ( V_13 ) ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_5 * V_25 = F_3 ( V_6 , V_8 ) ;
struct V_23 * V_9 = V_6 -> V_9 [ V_8 -> V_10 ] ;
struct V_19 * V_20 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
int V_21 ;
if ( V_6 -> V_24 && V_6 -> V_24 -> V_30 )
return F_15 ( V_8 ,
V_6 -> V_24 -> V_30 ) ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_31 = V_32 | V_33 |
V_34 ;
V_29 . V_35 = 2 ;
V_29 . V_36 = V_37 ;
V_29 . V_38 = 256 ;
V_29 . V_39 = F_16 ( V_25 ) ;
V_29 . V_40 = V_41 ;
V_29 . V_42 = V_20 -> V_42 ;
V_21 = F_17 ( V_9 , & V_27 ) ;
if ( V_21 == 0 ) {
if ( V_27 . V_43 )
V_29 . V_31 |= V_44 | V_45 ;
}
return F_15 ( V_8 , & V_29 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = V_8 -> V_18 ;
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_23 * V_9 = V_6 -> V_9 [ V_8 -> V_10 ] ;
int V_21 ;
V_21 = F_14 ( V_8 ) ;
if ( V_21 )
return V_21 ;
return F_19 ( V_8 , V_9 ) ;
}
static void F_20 ( struct V_46 * V_6 )
{
F_21 ( V_6 ) ;
}
static struct V_23 * F_22 (
struct V_16 * V_17 ,
struct V_7 * V_8 )
{
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
struct V_19 * V_20 ;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
if ( ( V_6 -> V_47 & V_48 ) && V_6 -> V_9 [ 0 ] )
return V_6 -> V_9 [ 0 ] ;
if ( V_6 -> V_24 -> V_49 )
return V_6 -> V_24 -> V_49 ( V_17 , V_8 ) ;
return F_23 ( V_6 -> V_24 -> V_50 ,
V_20 -> V_51 ) ;
}
static int F_24 ( struct V_16 * V_17 )
{
struct V_1 * V_6 = F_1 ( V_17 -> V_4 ) ;
const struct V_52 * V_24 = V_6 -> V_24 ;
struct V_5 * V_11 = V_17 -> V_4 -> V_11 ;
struct V_19 * V_20 ;
struct V_7 * V_8 ;
T_1 V_53 ;
T_1 V_54 ;
unsigned int V_55 ;
int V_21 ;
if ( V_24 && V_24 -> V_53 ) {
V_53 = V_24 -> V_53 ;
V_54 = V_24 -> V_30 -> V_40 ;
} else {
V_53 = 512 * 1024 ;
V_54 = V_41 ;
}
for ( V_55 = V_56 ; V_55 <= V_57 ; V_55 ++ ) {
V_8 = V_17 -> V_6 -> V_58 [ V_55 ] . V_8 ;
if ( ! V_8 )
continue;
V_20 = F_5 ( V_17 -> V_22 , V_8 ) ;
if ( ! V_6 -> V_9 [ V_55 ] &&
( V_6 -> V_47 & V_59 ) )
V_6 -> V_9 [ V_55 ] = F_25 ( V_11 ,
V_20 -> V_60 ) ;
if ( ! V_6 -> V_9 [ V_55 ] && ( V_6 -> V_47 & V_61 ) ) {
V_6 -> V_9 [ V_55 ] = F_22 ( V_17 ,
V_8 ) ;
}
if ( ! V_6 -> V_9 [ V_55 ] ) {
F_26 ( V_17 -> V_4 -> V_11 ,
L_1 , V_55 ) ;
V_21 = - V_62 ;
goto V_63;
}
V_21 = F_27 ( V_8 ,
V_64 ,
F_3 ( V_6 , V_8 ) ,
V_53 ,
V_54 ) ;
if ( V_21 )
goto V_63;
}
return 0 ;
V_63:
F_20 ( V_17 -> V_6 ) ;
return V_21 ;
}
static void F_28 ( struct V_1 * V_6 ,
struct V_5 * V_11 )
{
unsigned int V_55 ;
if ( ( V_6 -> V_47 & ( V_65 |
V_59 ) ) ||
! V_11 -> V_66 )
return;
if ( V_6 -> V_47 & V_48 ) {
V_6 -> V_9 [ 0 ] = F_25 ( V_11 , L_2 ) ;
V_6 -> V_9 [ 1 ] = V_6 -> V_9 [ 0 ] ;
} else {
for ( V_55 = V_56 ; V_55 <= V_57 ; V_55 ++ ) {
V_6 -> V_9 [ V_55 ] = F_25 ( V_11 ,
V_67 [ V_55 ] ) ;
}
}
}
static void F_29 ( struct V_1 * V_6 )
{
unsigned int V_55 ;
for ( V_55 = V_56 ; V_55 <= V_57 ;
V_55 ++ ) {
if ( ! V_6 -> V_9 [ V_55 ] )
continue;
F_30 ( V_6 -> V_9 [ V_55 ] ) ;
if ( V_6 -> V_47 & V_48 )
break;
}
}
int F_31 ( struct V_5 * V_11 ,
const struct V_52 * V_24 , unsigned int V_47 )
{
struct V_1 * V_6 ;
int V_21 ;
V_6 = F_32 ( sizeof( * V_6 ) , V_68 ) ;
if ( ! V_6 )
return - V_69 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_47 = V_47 ;
F_28 ( V_6 , V_11 ) ;
if ( V_47 & V_70 )
V_21 = F_33 ( V_11 , & V_6 -> V_4 ,
& V_71 ) ;
else
V_21 = F_33 ( V_11 , & V_6 -> V_4 ,
& V_72 ) ;
if ( V_21 )
goto V_73;
return 0 ;
V_73:
F_29 ( V_6 ) ;
F_34 ( V_6 ) ;
return V_21 ;
}
void F_35 ( struct V_5 * V_11 )
{
struct V_2 * V_4 ;
struct V_1 * V_6 ;
V_4 = F_36 ( V_11 ) ;
if ( ! V_4 )
return;
V_6 = F_1 ( V_4 ) ;
F_37 ( V_4 ) ;
F_29 ( V_6 ) ;
F_34 ( V_6 ) ;
}

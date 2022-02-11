static T_1 *
F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
if ( V_3 ) {
if ( V_3 [ 0 ] >= 0x30 && V_3 [ 1 ] >= 0x0c )
return F_3 ( V_2 , V_3 [ 0x0a ] ) ;
if ( V_3 [ 0 ] >= 0x22 && V_3 [ - 1 ] >= 0x13 )
return F_3 ( V_2 , V_3 [ - 15 ] ) ;
}
return NULL ;
}
static T_1 *
F_4 ( struct V_1 * V_2 , int V_4 , int V_5 , T_1 * V_6 )
{
T_1 * V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
* V_6 = V_7 [ 0 ] ;
if ( * V_6 < 0x30 && V_5 < V_7 [ 2 ] )
return V_7 + 3 + ( V_5 * V_7 [ 1 ] ) ;
else if ( V_5 < V_7 [ 2 ] )
return V_7 + V_7 [ 1 ] + ( V_5 * V_7 [ 3 ] ) ;
}
return NULL ;
}
int
F_5 ( struct V_1 * V_2 , int V_4 , int line , int V_8 , int V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
return V_14 -> V_17 ? V_14 -> V_17 ( V_2 , line , V_8 , V_9 ) : - V_18 ;
}
int
F_6 ( struct V_1 * V_2 , int V_4 , int line )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
return V_14 -> V_19 ? V_14 -> V_19 ( V_2 , line ) : - V_18 ;
}
int
F_7 ( struct V_1 * V_2 , int V_4 , T_1 V_20 , T_1 line ,
struct V_21 * V_16 )
{
T_1 * V_7 , * V_22 , V_6 ;
int V_23 = - 1 ;
if ( line == 0xff && V_20 == 0xff )
return - V_24 ;
while ( ( V_22 = F_4 ( V_2 , V_4 , ++ V_23 , & V_6 ) ) ) {
if ( V_6 < 0x40 ) {
T_2 V_25 = F_8 ( V_22 [ 0 ] ) ;
* V_16 = (struct V_21 ) {
. line = ( V_25 & 0x001f ) >> 0 ,
. V_20 = ( V_25 & 0x07e0 ) >> 5 ,
. log [ 0 ] = ( V_25 & 0x1800 ) >> 11 ,
. log [ 1 ] = ( V_25 & 0x6000 ) >> 13 ,
} ;
} else
if ( V_6 < 0x41 ) {
* V_16 = (struct V_21 ) {
. line = V_22 [ 0 ] & 0x1f ,
. V_20 = V_22 [ 1 ] ,
. log [ 0 ] = ( V_22 [ 3 ] & 0x18 ) >> 3 ,
. log [ 1 ] = ( V_22 [ 3 ] & 0x60 ) >> 5 ,
} ;
} else {
* V_16 = (struct V_21 ) {
. line = V_22 [ 0 ] & 0x3f ,
. V_20 = V_22 [ 1 ] ,
. log [ 0 ] = ( V_22 [ 4 ] & 0x30 ) >> 4 ,
. log [ 1 ] = ( V_22 [ 4 ] & 0xc0 ) >> 6 ,
} ;
}
if ( ( line == 0xff || line == V_16 -> line ) &&
( V_20 == 0xff || V_20 == V_16 -> V_20 ) )
return 0 ;
}
if ( ( V_7 = F_2 ( V_2 ) ) && V_7 [ 0 ] >= 0x22 ) {
if ( V_20 == V_26 ) {
* V_16 = (struct V_21 ) {
. V_20 = V_26 ,
. line = V_7 [ - 4 ] >> 4 ,
. log [ 0 ] = ! ! ( V_7 [ - 5 ] & 2 ) ,
. log [ 1 ] = ! ( V_7 [ - 5 ] & 2 ) ,
} ;
return 0 ;
}
}
if ( F_9 ( V_2 , 0x0189 , 0x10de , 0x0010 ) ) {
if ( V_20 == V_26 ) {
* V_16 = (struct V_21 ) {
. V_20 = V_26 ,
. line = 4 ,
. log [ 0 ] = 0 ,
. log [ 1 ] = 1 ,
} ;
return 0 ;
}
}
return - V_24 ;
}
int
F_10 ( struct V_1 * V_2 , int V_4 , T_1 V_27 , T_1 line , int V_28 )
{
struct V_21 V_16 ;
int V_29 ;
V_29 = F_7 ( V_2 , V_4 , V_27 , line , & V_16 ) ;
if ( V_29 == 0 ) {
int V_8 = ! ! ( V_16 . log [ V_28 ] & 0x02 ) ;
int V_9 = ! ! ( V_16 . log [ V_28 ] & 0x01 ) ;
V_29 = F_5 ( V_2 , V_4 , V_16 . line , V_8 , V_9 ) ;
}
return V_29 ;
}
int
F_11 ( struct V_1 * V_2 , int V_4 , T_1 V_27 , T_1 line )
{
struct V_21 V_16 ;
int V_29 ;
V_29 = F_7 ( V_2 , V_4 , V_27 , line , & V_16 ) ;
if ( V_29 == 0 ) {
V_29 = F_6 ( V_2 , V_4 , V_16 . line ) ;
if ( V_29 >= 0 )
V_29 = ( V_29 == ( V_16 . log [ 1 ] & 1 ) ) ;
}
return V_29 ;
}
int
F_12 ( struct V_1 * V_2 , int V_4 , T_1 V_27 , T_1 line , bool V_30 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
struct V_21 V_16 ;
int V_29 ;
V_29 = F_7 ( V_2 , V_4 , V_27 , line , & V_16 ) ;
if ( V_29 == 0 ) {
if ( V_4 == 0 && V_14 -> V_31 )
V_14 -> V_31 ( V_2 , V_16 . line , V_30 ) ;
else
V_29 = - V_18 ;
}
return V_29 ;
}
static void
F_13 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_14 ( V_33 , struct V_34 , V_33 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
unsigned long V_36 ;
int V_28 ;
V_28 = F_11 ( V_2 , V_35 -> V_4 , V_35 -> V_20 . V_20 , V_35 -> V_20 . line ) ;
if ( V_28 >= 0 )
V_35 -> V_37 ( V_35 -> V_25 , V_28 ) ;
F_15 ( & V_14 -> V_38 , V_36 ) ;
V_35 -> V_39 = false ;
F_16 ( & V_14 -> V_38 , V_36 ) ;
}
void
F_17 ( struct V_1 * V_2 , int V_4 , T_3 V_40 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
struct V_34 * V_35 ;
if ( V_4 != 0 )
return;
F_18 ( & V_14 -> V_38 ) ;
F_19 (isr, &pgpio->isr, head) {
if ( V_40 & ( 1 << V_35 -> V_20 . line ) ) {
if ( V_35 -> V_39 )
continue;
V_35 -> V_39 = true ;
F_20 ( & V_35 -> V_33 ) ;
}
}
F_21 ( & V_14 -> V_38 ) ;
}
int
F_22 ( struct V_1 * V_2 , int V_4 , T_1 V_27 , T_1 line ,
void (* V_37)( void * , int ) , void * V_25 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
struct V_34 * V_35 ;
unsigned long V_36 ;
int V_29 ;
V_35 = F_23 ( sizeof( * V_35 ) , V_41 ) ;
if ( ! V_35 )
return - V_42 ;
V_29 = F_7 ( V_2 , V_4 , V_27 , line , & V_35 -> V_20 ) ;
if ( V_29 ) {
F_24 ( V_35 ) ;
return V_29 ;
}
F_25 ( & V_35 -> V_33 , F_13 ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_25 = V_25 ;
V_35 -> V_4 = V_4 ;
F_15 ( & V_14 -> V_38 , V_36 ) ;
F_26 ( & V_35 -> V_43 , & V_14 -> V_35 ) ;
F_16 ( & V_14 -> V_38 , V_36 ) ;
return 0 ;
}
void
F_27 ( struct V_1 * V_2 , int V_4 , T_1 V_27 , T_1 line ,
void (* V_37)( void * , int ) , void * V_25 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
struct V_34 * V_35 , * V_44 ;
struct V_21 V_20 ;
unsigned long V_36 ;
F_28 ( V_45 ) ;
int V_29 ;
V_29 = F_7 ( V_2 , V_4 , V_27 , line , & V_20 ) ;
if ( V_29 == 0 ) {
F_15 ( & V_14 -> V_38 , V_36 ) ;
F_29 (isr, tmp, &pgpio->isr, head) {
if ( memcmp ( & V_35 -> V_20 , & V_20 , sizeof( V_20 ) ) ||
V_35 -> V_4 != V_4 ||
V_35 -> V_37 != V_37 || V_35 -> V_25 != V_25 )
continue;
F_30 ( & V_35 -> V_43 , & V_45 ) ;
}
F_16 ( & V_14 -> V_38 , V_36 ) ;
F_29 (isr, tmp, &tofree, head) {
F_31 ( & V_35 -> V_33 ) ;
F_24 ( V_35 ) ;
}
}
}
int
F_32 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
F_33 ( & V_14 -> V_35 ) ;
F_34 ( & V_14 -> V_38 ) ;
return F_35 ( V_2 ) ;
}
void
F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
F_37 ( V_2 ) ;
F_38 ( ! F_39 ( & V_14 -> V_35 ) ) ;
}
int
F_35 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
int V_29 = 0 ;
if ( V_14 -> V_46 )
V_29 = V_14 -> V_46 ( V_2 ) ;
return V_29 ;
}
void
F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_16 ;
if ( V_14 -> V_47 )
V_14 -> V_47 ( V_2 ) ;
}
void
F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
T_1 * V_22 , V_6 ;
int V_5 = - 1 ;
while ( ( V_22 = F_4 ( V_2 , 0 , ++ V_5 , & V_6 ) ) ) {
T_1 V_20 = 0xff , line , V_48 , V_49 , V_50 ;
if ( V_6 >= 0x41 ) {
V_48 = ! ! ( V_22 [ 0 ] & 0x80 ) ;
line = V_22 [ 0 ] & 0x3f ;
V_20 = V_22 [ 1 ] ;
V_49 = V_22 [ 2 ] ;
V_50 = V_22 [ 3 ] & 0x1f ;
} else
if ( V_6 >= 0x40 ) {
line = V_22 [ 0 ] & 0x1f ;
V_20 = V_22 [ 1 ] ;
V_48 = ! ! ( V_22 [ 3 ] & 0x01 ) ;
V_49 = ! ! ( V_22 [ 3 ] & 0x02 ) ;
V_50 = ! ! ( V_22 [ 3 ] & 0x04 ) ;
} else {
break;
}
if ( V_20 == 0xff )
continue;
F_41 ( V_2 , V_20 , V_48 ) ;
if ( V_11 -> V_51 >= V_52 ) {
F_42 ( V_2 , 0x00d610 + ( line * 4 ) , 0xff , V_49 ) ;
if ( V_50 -- )
F_42 ( V_2 , 0x00d640 + ( V_50 * 4 ) , 0xff , line ) ;
} else
if ( V_11 -> V_51 >= V_53 ) {
static const T_3 V_54 [] = { 0xe100 , 0xe28c } ;
T_3 V_55 = ( V_50 << 16 ) | V_49 ;
T_3 V_56 = V_54 [ line >> 4 ] ; line &= 0x0f ;
F_42 ( V_2 , V_56 , 0x00010001 << line , V_55 << line ) ;
}
}
}

int F_1 ( int V_1 , struct V_2 * * V_3 )
{
struct V_2 * V_4 ;
* V_3 = NULL ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return - V_6 ;
if ( V_1 > 0 ) {
V_4 -> V_7 = F_3 ( V_1 , V_5 ) ;
if ( V_4 -> V_7 == NULL ) {
F_4 ( V_4 ) ;
return - V_6 ;
}
}
V_4 -> V_1 = V_1 ;
V_4 -> V_8 = 0xff ;
V_4 -> type = V_9 ;
F_5 ( & V_4 -> V_10 ) ;
* V_3 = V_4 ;
return 0 ;
}
void F_6 ( struct V_2 * V_4 )
{
if ( V_4 != NULL ) {
F_4 ( V_4 -> V_7 ) ;
F_4 ( V_4 ) ;
}
}
static inline void F_7 ( struct V_2 * V_4 )
{
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
V_4 -> type = V_9 ;
}
void F_8 ( struct V_2 * V_4 )
{
unsigned long V_13 ;
F_9 ( & V_4 -> V_10 , V_13 ) ;
F_7 ( V_4 ) ;
F_10 ( & V_4 -> V_10 , V_13 ) ;
}
void F_11 ( struct V_2 * V_4 )
{
unsigned long V_13 ;
F_9 ( & V_4 -> V_10 , V_13 ) ;
V_4 -> V_8 = 0xff ;
F_10 ( & V_4 -> V_10 , V_13 ) ;
}
void F_12 ( struct V_2 * V_4 , int V_14 )
{
V_4 -> V_15 = V_14 ? 1 : 0 ;
}
long F_13 ( struct V_2 * V_4 , unsigned char * V_7 , long V_16 ,
struct V_17 * V_18 )
{
long V_19 = 0 ;
int V_20 ;
V_18 -> type = V_21 ;
while ( V_16 -- > 0 ) {
V_20 = F_14 ( V_4 , * V_7 ++ , V_18 ) ;
V_19 ++ ;
if ( V_20 < 0 )
return V_20 ;
else if ( V_20 > 0 )
return V_19 ;
}
return V_19 ;
}
int F_14 ( struct V_2 * V_4 , int V_22 ,
struct V_17 * V_18 )
{
int V_20 = 0 ;
unsigned long V_13 ;
V_22 &= 0xff ;
if ( V_22 >= V_23 ) {
V_18 -> type = V_24 [ V_25 + V_22 - 0xf0 ] . V_26 ;
V_18 -> V_13 &= ~ V_27 ;
V_18 -> V_13 |= V_28 ;
return V_18 -> type != V_21 ;
}
F_9 ( & V_4 -> V_10 , V_13 ) ;
if ( ( V_22 & 0x80 ) &&
( V_22 != V_29 || V_4 -> type != V_30 ) ) {
V_4 -> V_7 [ 0 ] = V_22 ;
if ( ( V_22 & 0xf0 ) == 0xf0 )
V_4 -> type = ( V_22 & 0x0f ) + V_25 ;
else
V_4 -> type = ( V_22 >> 4 ) & 0x07 ;
V_4 -> V_11 = 1 ;
V_4 -> V_12 = V_24 [ V_4 -> type ] . V_12 ;
} else {
if ( V_4 -> V_12 > 0 ) {
V_4 -> V_7 [ V_4 -> V_11 ++ ] = V_22 ;
if ( V_4 -> type != V_30 )
V_4 -> V_12 -- ;
} else {
V_4 -> V_7 [ 1 ] = V_22 ;
V_4 -> V_12 = V_24 [ V_4 -> type ] . V_12 - 1 ;
V_4 -> V_11 = 2 ;
}
}
if ( V_4 -> V_12 == 0 ) {
V_18 -> type = V_24 [ V_4 -> type ] . V_26 ;
V_18 -> V_13 &= ~ V_27 ;
V_18 -> V_13 |= V_28 ;
if ( V_24 [ V_4 -> type ] . V_31 )
V_24 [ V_4 -> type ] . V_31 ( V_4 , V_18 ) ;
if ( V_4 -> type >= V_25 )
V_4 -> type = V_9 ;
V_20 = 1 ;
} else if ( V_4 -> type == V_30 ) {
if ( V_22 == V_29 ||
V_4 -> V_11 >= V_4 -> V_1 ) {
V_18 -> V_13 &= ~ V_27 ;
V_18 -> V_13 |= V_32 ;
V_18 -> type = V_33 ;
V_18 -> V_34 . V_35 . V_36 = V_4 -> V_11 ;
V_18 -> V_34 . V_35 . V_37 = V_4 -> V_7 ;
if ( V_22 != V_29 )
V_4 -> V_11 = 0 ;
else
F_7 ( V_4 ) ;
V_20 = 1 ;
}
}
F_10 ( & V_4 -> V_10 , V_13 ) ;
return V_20 ;
}
static void F_15 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_38 . V_39 = V_4 -> V_7 [ 0 ] & 0x0f ;
V_18 -> V_34 . V_38 . V_38 = V_4 -> V_7 [ 1 ] ;
V_18 -> V_34 . V_38 . V_40 = V_4 -> V_7 [ 2 ] ;
}
static void F_16 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_41 . V_39 = V_4 -> V_7 [ 0 ] & 0x0f ;
V_18 -> V_34 . V_41 . V_42 = V_4 -> V_7 [ 1 ] ;
}
static void F_17 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_41 . V_39 = V_4 -> V_7 [ 0 ] & 0x0f ;
V_18 -> V_34 . V_41 . V_42 = ( int ) V_4 -> V_7 [ 2 ] * 128 + ( int ) V_4 -> V_7 [ 1 ] - 8192 ;
}
static void F_18 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_41 . V_39 = V_4 -> V_7 [ 0 ] & 0x0f ;
V_18 -> V_34 . V_41 . V_43 = V_4 -> V_7 [ 1 ] ;
V_18 -> V_34 . V_41 . V_42 = V_4 -> V_7 [ 2 ] ;
}
static void F_19 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_41 . V_42 = V_4 -> V_7 [ 1 ] ;
}
static void F_20 ( struct V_2 * V_4 , struct V_17 * V_18 )
{
V_18 -> V_34 . V_41 . V_42 = ( int ) V_4 -> V_7 [ 2 ] * 128 + ( int ) V_4 -> V_7 [ 1 ] ;
}
long F_21 ( struct V_2 * V_4 , unsigned char * V_7 , long V_16 ,
struct V_17 * V_18 )
{
unsigned int V_44 , type ;
if ( V_18 -> type == V_21 )
return - V_45 ;
for ( type = 0 ; type < F_22 ( V_24 ) ; type ++ ) {
if ( V_18 -> type == V_24 [ type ] . V_26 )
goto V_46;
}
for ( type = 0 ; type < F_22 ( V_47 ) ; type ++ ) {
if ( V_18 -> type == V_47 [ type ] . V_26 )
return V_47 [ type ] . F_23 ( V_4 , V_7 , V_16 , V_18 ) ;
}
return - V_45 ;
V_46:
if ( type >= V_25 )
V_44 = 0xf0 + ( type - V_25 ) ;
else
V_44 = 0x80 | ( type << 4 ) | ( V_18 -> V_34 . V_38 . V_39 & 0x0f ) ;
if ( V_44 == V_48 ) {
F_11 ( V_4 ) ;
return F_24 ( V_18 , V_16 , V_7 , 1 , 0 ) ;
} else {
int V_12 ;
unsigned char V_49 [ 4 ] ;
unsigned long V_13 ;
F_9 ( & V_4 -> V_10 , V_13 ) ;
if ( ( V_44 & 0xf0 ) == 0xf0 || V_4 -> V_8 != V_44 || V_4 -> V_15 ) {
V_4 -> V_8 = V_44 ;
F_10 ( & V_4 -> V_10 , V_13 ) ;
V_49 [ 0 ] = V_44 ;
if ( V_24 [ type ] . F_23 )
V_24 [ type ] . F_23 ( V_18 , V_49 + 1 ) ;
V_12 = V_24 [ type ] . V_12 + 1 ;
} else {
F_10 ( & V_4 -> V_10 , V_13 ) ;
if ( V_24 [ type ] . F_23 )
V_24 [ type ] . F_23 ( V_18 , V_49 + 0 ) ;
V_12 = V_24 [ type ] . V_12 ;
}
if ( V_16 < V_12 )
return - V_6 ;
memcpy ( V_7 , V_49 , V_12 ) ;
return V_12 ;
}
}
static void F_25 ( struct V_17 * V_18 , unsigned char * V_7 )
{
V_7 [ 0 ] = V_18 -> V_34 . V_38 . V_38 & 0x7f ;
V_7 [ 1 ] = V_18 -> V_34 . V_38 . V_40 & 0x7f ;
}
static void F_26 ( struct V_17 * V_18 , unsigned char * V_7 )
{
V_7 [ 0 ] = V_18 -> V_34 . V_41 . V_42 & 0x7f ;
}
static void F_27 ( struct V_17 * V_18 , unsigned char * V_7 )
{
int V_42 = V_18 -> V_34 . V_41 . V_42 + 8192 ;
V_7 [ 0 ] = V_42 & 0x7f ;
V_7 [ 1 ] = ( V_42 >> 7 ) & 0x7f ;
}
static void F_28 ( struct V_17 * V_18 , unsigned char * V_7 )
{
V_7 [ 0 ] = V_18 -> V_34 . V_41 . V_43 & 0x7f ;
V_7 [ 1 ] = V_18 -> V_34 . V_41 . V_42 & 0x7f ;
}
static void F_29 ( struct V_17 * V_18 , unsigned char * V_7 )
{
V_7 [ 0 ] = V_18 -> V_34 . V_41 . V_42 & 0x7f ;
V_7 [ 1 ] = ( V_18 -> V_34 . V_41 . V_42 >> 7 ) & 0x7f ;
}
static int F_30 ( struct V_2 * V_4 , unsigned char * V_7 ,
int V_16 , struct V_17 * V_18 )
{
unsigned char V_44 ;
int V_50 = 0 ;
V_44 = V_51 | ( V_18 -> V_34 . V_41 . V_39 & 0x0f ) ;
if ( V_18 -> V_34 . V_41 . V_43 < 0x20 ) {
if ( V_16 < 4 )
return - V_6 ;
if ( V_4 -> V_15 && V_16 < 6 )
return - V_6 ;
if ( V_44 != V_4 -> V_8 || V_4 -> V_15 ) {
if ( V_16 < 5 )
return - V_6 ;
V_7 [ V_50 ++ ] = V_4 -> V_8 = V_44 ;
}
V_7 [ V_50 ++ ] = V_18 -> V_34 . V_41 . V_43 ;
V_7 [ V_50 ++ ] = ( V_18 -> V_34 . V_41 . V_42 >> 7 ) & 0x7f ;
if ( V_4 -> V_15 )
V_7 [ V_50 ++ ] = V_44 ;
V_7 [ V_50 ++ ] = V_18 -> V_34 . V_41 . V_43 + 0x20 ;
V_7 [ V_50 ++ ] = V_18 -> V_34 . V_41 . V_42 & 0x7f ;
} else {
if ( V_16 < 2 )
return - V_6 ;
if ( V_44 != V_4 -> V_8 || V_4 -> V_15 ) {
if ( V_16 < 3 )
return - V_6 ;
V_7 [ V_50 ++ ] = V_4 -> V_8 = V_44 ;
}
V_7 [ V_50 ++ ] = V_18 -> V_34 . V_41 . V_43 & 0x7f ;
V_7 [ V_50 ++ ] = V_18 -> V_34 . V_41 . V_42 & 0x7f ;
}
return V_50 ;
}
static int F_31 ( struct V_2 * V_4 , unsigned char * V_7 ,
int V_16 , struct V_17 * V_18 )
{
unsigned char V_44 ;
char * V_52 ;
static char V_53 [ 4 ] = { V_54 ,
V_55 ,
V_56 ,
V_57 } ;
static char V_58 [ 4 ] = { V_59 ,
V_60 ,
V_56 ,
V_57 } ;
unsigned char V_61 [ 4 ] ;
int V_50 = 0 , V_62 ;
if ( V_16 < 8 )
return - V_6 ;
if ( V_4 -> V_15 && V_16 < 12 )
return - V_6 ;
V_44 = V_51 | ( V_18 -> V_34 . V_41 . V_39 & 0x0f ) ;
V_61 [ 0 ] = ( V_18 -> V_34 . V_41 . V_43 & 0x3f80 ) >> 7 ;
V_61 [ 1 ] = V_18 -> V_34 . V_41 . V_43 & 0x007f ;
V_61 [ 2 ] = ( V_18 -> V_34 . V_41 . V_42 & 0x3f80 ) >> 7 ;
V_61 [ 3 ] = V_18 -> V_34 . V_41 . V_42 & 0x007f ;
if ( V_44 != V_4 -> V_8 && ! V_4 -> V_15 ) {
if ( V_16 < 9 )
return - V_6 ;
V_7 [ V_50 ++ ] = V_4 -> V_8 = V_44 ;
}
V_52 = V_18 -> type == V_63 ? V_53 : V_58 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
if ( V_4 -> V_15 )
V_7 [ V_50 ++ ] = V_4 -> V_8 = V_44 ;
V_7 [ V_50 ++ ] = V_52 [ V_62 ] ;
V_7 [ V_50 ++ ] = V_61 [ V_62 ] ;
}
return V_50 ;
}
static int T_1 F_32 ( void )
{
return 0 ;
}
static void T_2 F_33 ( void )
{
}

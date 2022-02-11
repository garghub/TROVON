static void F_1 ( int V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 , * * V_7 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 ) {
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_1 = V_1 ;
F_3 ( & V_9 ) ;
for ( V_7 = & V_10 ; * V_7 && ( * V_7 ) -> V_1 < V_1 ; V_7 = & ( * V_7 ) -> V_11 )
;
V_6 -> V_11 = * V_7 ;
* V_7 = V_6 ;
F_4 ( & V_9 ) ;
}
}
static struct V_2 * F_5 ( struct V_2 * V_12 , int V_13 )
{
struct V_2 * V_14 = F_6 ( V_12 -> V_15 ,
V_12 -> V_16 ,
V_12 -> V_17 ,
V_12 -> V_18 ) ;
if ( V_14 ) {
V_14 -> V_19 = V_12 -> V_19 ;
V_14 -> V_20 = V_12 ;
V_14 -> V_13 = V_13 ;
V_12 -> V_21 [ V_13 - 1 ] = V_14 ;
}
return V_14 ;
}
int F_7 ( struct V_2 * V_3 )
{
int V_22 = 0 ;
char * V_23 ;
static const char * V_24 [] = { L_1 , L_2 , L_3 , L_4 , L_1 } ;
int V_25 ;
int V_26 ;
int V_27 = 0 ;
V_28:
if ( V_3 -> V_13 < 0 && F_8 ( V_3 ) &&
( ( V_25 = F_9 ( V_3 ) ) == 2 || V_25 == 4 ) ) {
V_3 -> V_13 = 0 ;
F_10 ( V_29
L_5 ,
V_3 -> V_30 , V_25 ) ;
for ( V_26 = 1 ; V_26 < V_25 ; V_26 ++ ) {
struct V_2 * V_14 = F_5 ( V_3 , V_26 ) ;
if ( ! V_14 ) {
if ( F_11 ( V_31 ) )
break;
F_12 () ;
continue;
}
F_10 ( V_29
L_6 ,
V_14 -> V_30 , V_26 + 1 , V_24 [ V_26 + 1 ] , V_25 ,
V_3 -> V_30 ) ;
F_7 ( V_14 ) ;
}
}
if ( V_3 -> V_13 >= 0 )
F_13 ( V_3 ) ;
F_14 ( V_3 ) ;
V_22 += F_15 ( V_3 ) ;
F_1 ( V_32 ++ , V_3 , - 1 ) ;
V_23 = F_2 ( 1024 , V_8 ) ;
if ( V_23 ) {
if ( F_16 ( V_32 - 1 , V_23 , 1024 ) > 2 )
V_22 ++ ;
F_17 ( V_23 ) ;
}
if ( ! V_22 && ! V_27 ) {
F_18 ( V_3 ) ;
F_19 ( V_3 , V_33 ) ;
F_20 ( 50 ) ;
F_19 ( V_3 ,
V_33 |
V_34 ) ;
F_20 ( 50 ) ;
V_27 = 1 ;
goto V_28;
}
return V_22 ;
}
void F_18 ( struct V_2 * V_3 )
{
struct V_5 * * V_7 ;
F_3 ( & V_9 ) ;
V_7 = & V_10 ;
while ( * V_7 ) {
struct V_5 * V_35 = * V_7 ;
if ( V_35 -> V_3 != V_3 ) {
V_7 = & V_35 -> V_11 ;
continue;
}
* V_7 = V_35 -> V_11 ;
F_17 ( V_35 ) ;
}
if ( ! V_10 ) V_32 = 0 ;
F_4 ( & V_9 ) ;
return;
}
struct V_36 * F_21 ( int V_1 , const char * V_30 )
{
struct V_5 * V_7 = V_10 ;
struct V_2 * V_3 ;
struct V_36 * V_35 ;
int V_4 ;
F_3 ( & V_9 ) ;
while ( V_7 && V_7 -> V_1 != V_1 )
V_7 = V_7 -> V_11 ;
if ( ! V_7 ) {
F_4 ( & V_9 ) ;
return NULL ;
}
V_4 = V_7 -> V_4 ;
V_3 = F_22 ( V_7 -> V_3 ) ;
F_4 ( & V_9 ) ;
V_35 = F_23 ( V_3 , V_30 , NULL , NULL , NULL , 0 , NULL ) ;
F_24 ( V_3 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_4 = V_4 ;
if ( V_4 >= 0 ) {
int V_37 ;
F_25 ( V_35 ) ;
V_37 = V_3 -> V_4 ;
F_26 ( V_35 ) ;
if ( V_37 != V_4 ) {
F_27 ( V_35 ) ;
return NULL ;
}
}
return V_35 ;
}
void F_28 ( struct V_36 * V_35 )
{
F_27 ( V_35 ) ;
}
static int F_29 ( struct V_2 * V_3 , int V_38 )
{
unsigned char V_39 ;
F_30 ( V_3 ) ;
F_31 ( V_3 , 0xaa ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x55 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x00 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0xff ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) & ( V_40
| V_41
| V_42
| V_43 ) ;
if ( V_39 != ( V_40
| V_41
| V_42
| V_43 ) ) {
F_33 ( V_44 L_7 ,
V_3 -> V_30 , V_39 ) ;
return - V_45 ;
}
F_31 ( V_3 , 0x87 ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) & ( V_40
| V_41
| V_42
| V_43 ) ;
if ( V_39 != ( V_42 | V_43 ) ) {
F_33 ( V_44 L_8 ,
V_3 -> V_30 , V_39 ) ;
return - V_45 ;
}
F_31 ( V_3 , 0x78 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , V_38 ) ; F_20 ( 2 ) ;
F_34 ( V_3 ,
V_46 ,
V_46 ) ;
F_20 ( 1 ) ;
V_39 = F_32 ( V_3 ) ;
F_34 ( V_3 , V_46 , 0 ) ;
F_20 ( 1 ) ;
F_31 ( V_3 , 0xff ) ; F_20 ( 2 ) ;
return V_39 ;
}
static int F_35 ( struct V_2 * V_3 , int V_38 )
{
unsigned char V_39 ;
int V_47 ;
F_30 ( V_3 ) ;
F_31 ( V_3 , 0xaa ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x55 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0xf0 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x0f ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x52 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0xad ) ; F_20 ( 2 ) ;
F_31 ( V_3 , V_38 ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) ;
if ( ! ( V_39 & V_48 ) ) {
F_33 ( V_44 L_9 ,
V_3 -> V_30 , V_38 , V_39 ) ;
return - V_49 ;
}
V_47 = ( ( ( V_39 & V_42 ? 1 : 0 ) << 0 ) |
( ( V_39 & V_41 ? 1 : 0 ) << 1 ) |
( ( V_39 & V_40 ? 0 : 1 ) << 2 ) |
( ( V_39 & V_43 ? 0 : 1 ) << 3 ) ) ;
return V_47 ;
}
void F_14 ( struct V_2 * V_3 )
{
F_29 ( V_3 , 0x30 ) ;
}
int F_36 ( struct V_2 * V_3 , int V_4 , int V_50 )
{
switch ( V_50 )
{
case V_51 :
case V_52 :
case V_53 :
return ! ( F_29 ( V_3 , 0x20 + V_4 ) &
V_43 ) ;
case V_54 :
case V_55 :
case V_56 :
return ! ( F_29 ( V_3 , 0xd0 + V_4 ) &
V_43 ) ;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
default:
return ! ( F_29 ( V_3 , 0xe0 + V_4 ) &
V_43 ) ;
}
}
static int F_8 ( struct V_2 * V_3 )
{
return F_35 ( V_3 , 0x51 ) == 3 ;
}
static int F_9 ( struct V_2 * V_3 )
{
return F_35 ( V_3 , 0x58 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_13 = V_3 -> V_13 ;
return F_35 ( V_3 , 0x60 + V_13 ) == V_13 ;
}
static int F_15 ( struct V_2 * V_3 )
{
unsigned char V_39 ;
unsigned char V_4 ;
int V_61 = V_32 ;
int V_22 ;
char * V_23 ;
F_30 ( V_3 ) ;
F_31 ( V_3 , 0xaa ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x55 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0x00 ) ; F_20 ( 2 ) ;
F_31 ( V_3 , 0xff ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) & ( V_40
| V_41
| V_42
| V_43 ) ;
if ( V_39 != ( V_40
| V_41
| V_42
| V_43 ) ) {
F_33 ( V_44 L_10 ,
V_3 -> V_30 , V_39 ) ;
return 0 ;
}
F_31 ( V_3 , 0x87 ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) & ( V_40
| V_41
| V_42
| V_43 ) ;
if ( V_39 != ( V_42 | V_43 ) ) {
F_33 ( V_44 L_11 ,
V_3 -> V_30 , V_39 ) ;
return 0 ;
}
F_31 ( V_3 , 0x78 ) ; F_20 ( 2 ) ;
V_39 = F_32 ( V_3 ) ;
for ( V_4 = 0 ;
( V_39 & ( V_41 | V_42 ) )
== ( V_41 | V_42 )
&& V_4 < 4 ;
++ V_4 ) {
F_31 ( V_3 , V_4 ) ;
F_20 ( 2 ) ;
F_34 ( V_3 ,
V_46 ,
V_46 ) ;
F_20 ( 1 ) ;
F_34 ( V_3 , V_46 , 0 ) ;
F_20 ( 1 ) ;
F_1 ( V_32 ++ , V_3 , V_4 ) ;
if ( ! ( V_39 & V_40 ) )
break;
V_39 = F_32 ( V_3 ) ;
}
F_31 ( V_3 , 0xff ) ; F_20 ( 2 ) ;
V_22 = V_32 - V_61 ;
F_33 ( V_44 L_12 , V_3 -> V_30 ,
V_22 ) ;
V_23 = F_2 ( 1024 , V_8 ) ;
if ( ! V_23 ) return 0 ;
for ( V_4 = 0 ; V_61 < V_32 ; V_61 ++ , V_4 ++ )
F_16 ( V_61 , V_23 , 1024 ) ;
F_17 ( V_23 ) ;
return V_22 ;
}

struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_5 = F_3 ( V_4 , sizeof( union V_7 ) , V_6 ) ;
if ( ! V_5 -> V_5 ) {
F_4 ( V_5 ) ;
return NULL ;
}
V_5 -> V_4 = V_4 ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = V_5 -> V_10 = 0 ;
F_5 ( & V_5 -> V_11 ) ;
F_6 ( & V_5 -> V_12 ) ;
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = ( unsigned long ) - 1 ;
return V_5 ;
}
void
F_7 ( struct V_1 * V_5 )
{
if ( V_5 ) {
F_4 ( V_5 -> V_5 ) ;
F_4 ( V_5 ) ;
}
}
void
F_8 ( struct V_1 * V_5 )
{
if ( V_5 -> V_8 ) {
V_5 -> V_8 = 0 ;
V_5 -> V_9 = V_5 -> V_10 = 0 ;
}
F_9 ( & V_5 -> V_11 ) ;
V_5 -> V_15 = ( unsigned long ) - 1 ;
}
int
F_10 ( struct V_1 * V_5 , int V_16 , unsigned char * V_17 , int V_18 )
{
union V_7 V_19 ;
int V_20 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_21 [ 0 ] = V_22 ;
V_19 . V_21 [ 2 ] = V_16 ;
while ( V_18 -- > 0 ) {
V_19 . V_21 [ 1 ] = * V_17 ++ ;
V_20 = F_11 ( V_5 , & V_19 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_12 ( void * V_23 , void * V_24 , int V_25 )
{
struct V_26 * V_27 = V_23 ;
return F_10 ( V_27 -> V_28 , V_27 -> V_16 , V_24 , V_25 ) ;
}
int F_13 ( struct V_1 * V_5 , int V_16 ,
struct V_29 * V_30 )
{
struct V_26 V_27 = {
. V_28 = V_5 ,
. V_16 = V_16
} ;
if ( ( V_30 -> V_31 & V_32 ) != V_33 )
return 0 ;
return F_14 ( V_30 , F_12 , & V_27 ) ;
}
int
F_11 ( struct V_1 * V_5 , union V_7 * V_30 )
{
unsigned long V_31 ;
F_15 ( & V_5 -> V_12 , V_31 ) ;
if ( V_5 -> V_8 >= V_5 -> V_4 - 1 ) {
F_16 ( & V_5 -> V_12 , V_31 ) ;
return - V_34 ;
}
memcpy ( & V_5 -> V_5 [ V_5 -> V_10 ] , V_30 , sizeof( * V_30 ) ) ;
V_5 -> V_10 = ( V_5 -> V_10 + 1 ) % V_5 -> V_4 ;
V_5 -> V_8 ++ ;
F_9 ( & V_5 -> V_11 ) ;
F_16 ( & V_5 -> V_12 , V_31 ) ;
return 0 ;
}
int
F_17 ( struct V_1 * V_5 , union V_7 * V_19 )
{
if ( V_5 -> V_8 == 0 )
return - V_35 ;
memcpy ( V_19 , & V_5 -> V_5 [ V_5 -> V_9 ] , sizeof( * V_19 ) ) ;
return 0 ;
}
void
F_18 ( struct V_1 * V_5 )
{
F_19 ( V_5 -> V_11 ,
( V_5 -> V_8 > 0 || V_5 -> V_9 == V_5 -> V_10 ) ,
V_5 -> V_13 ) ;
}
void
F_20 ( struct V_1 * V_5 )
{
if ( V_5 -> V_8 > 0 ) {
V_5 -> V_9 = ( V_5 -> V_9 + 1 ) % V_5 -> V_4 ;
V_5 -> V_8 -- ;
}
}
unsigned int
F_21 ( struct V_1 * V_5 , struct V_36 * V_36 , T_1 * V_37 )
{
F_22 ( V_36 , & V_5 -> V_11 , V_37 ) ;
return V_5 -> V_8 ;
}
int
F_23 ( struct V_1 * V_5 , unsigned long V_38 , int V_39 )
{
if ( V_38 != V_5 -> V_15 ) {
union V_7 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
switch ( V_39 ) {
case V_40 :
V_19 . V_41 = ( V_38 << 8 ) | V_42 ;
F_11 ( V_5 , & V_19 ) ;
break;
case V_43 :
V_19 . V_44 . V_45 = V_46 ;
V_19 . V_44 . V_47 = V_48 ;
V_19 . V_44 . time = V_38 ;
F_11 ( V_5 , & V_19 ) ;
break;
}
V_5 -> V_15 = V_38 ;
}
return 0 ;
}
void
F_24 ( struct V_1 * V_5 , struct V_49 * V_24 )
{
F_25 ( V_24 , L_1 ,
( F_26 ( & V_5 -> V_11 ) ? L_2 : L_3 ) ,
V_5 -> V_8 , V_5 -> V_15 ) ;
}

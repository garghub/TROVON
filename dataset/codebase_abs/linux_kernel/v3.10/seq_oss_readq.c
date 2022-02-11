struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
if ( ( V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ) == NULL ) {
F_3 ( V_7 L_1 ) ;
return NULL ;
}
if ( ( V_5 -> V_5 = F_4 ( V_4 , sizeof( union V_8 ) , V_6 ) ) == NULL ) {
F_3 ( V_7 L_2 ) ;
F_5 ( V_5 ) ;
return NULL ;
}
V_5 -> V_4 = V_4 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = V_5 -> V_11 = 0 ;
F_6 ( & V_5 -> V_12 ) ;
F_7 ( & V_5 -> V_13 ) ;
V_5 -> V_14 = V_15 ;
V_5 -> V_16 = ( unsigned long ) - 1 ;
return V_5 ;
}
void
F_8 ( struct V_1 * V_5 )
{
if ( V_5 ) {
F_5 ( V_5 -> V_5 ) ;
F_5 ( V_5 ) ;
}
}
void
F_9 ( struct V_1 * V_5 )
{
if ( V_5 -> V_9 ) {
V_5 -> V_9 = 0 ;
V_5 -> V_10 = V_5 -> V_11 = 0 ;
}
if ( F_10 ( & V_5 -> V_12 ) )
F_11 ( & V_5 -> V_12 ) ;
V_5 -> V_16 = ( unsigned long ) - 1 ;
}
int
F_12 ( struct V_1 * V_5 , int V_17 , unsigned char * V_18 , int V_19 )
{
union V_8 V_20 ;
int V_21 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_22 [ 0 ] = V_23 ;
V_20 . V_22 [ 2 ] = V_17 ;
while ( V_19 -- > 0 ) {
V_20 . V_22 [ 1 ] = * V_18 ++ ;
V_21 = F_13 ( V_5 , & V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
int
F_13 ( struct V_1 * V_5 , union V_8 * V_24 )
{
unsigned long V_25 ;
F_14 ( & V_5 -> V_13 , V_25 ) ;
if ( V_5 -> V_9 >= V_5 -> V_4 - 1 ) {
F_15 ( & V_5 -> V_13 , V_25 ) ;
return - V_26 ;
}
memcpy ( & V_5 -> V_5 [ V_5 -> V_11 ] , V_24 , sizeof( * V_24 ) ) ;
V_5 -> V_11 = ( V_5 -> V_11 + 1 ) % V_5 -> V_4 ;
V_5 -> V_9 ++ ;
if ( F_10 ( & V_5 -> V_12 ) )
F_11 ( & V_5 -> V_12 ) ;
F_15 ( & V_5 -> V_13 , V_25 ) ;
return 0 ;
}
int
F_16 ( struct V_1 * V_5 , union V_8 * V_20 )
{
if ( V_5 -> V_9 == 0 )
return - V_27 ;
memcpy ( V_20 , & V_5 -> V_5 [ V_5 -> V_10 ] , sizeof( * V_20 ) ) ;
return 0 ;
}
void
F_17 ( struct V_1 * V_5 )
{
F_18 ( V_5 -> V_12 ,
( V_5 -> V_9 > 0 || V_5 -> V_10 == V_5 -> V_11 ) ,
V_5 -> V_14 ) ;
}
void
F_19 ( struct V_1 * V_5 )
{
if ( V_5 -> V_9 > 0 ) {
V_5 -> V_10 = ( V_5 -> V_10 + 1 ) % V_5 -> V_4 ;
V_5 -> V_9 -- ;
}
}
unsigned int
F_20 ( struct V_1 * V_5 , struct V_28 * V_28 , T_1 * V_29 )
{
F_21 ( V_28 , & V_5 -> V_12 , V_29 ) ;
return V_5 -> V_9 ;
}
int
F_22 ( struct V_1 * V_5 , unsigned long V_30 , int V_31 )
{
if ( V_30 != V_5 -> V_16 ) {
union V_8 V_20 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
switch ( V_31 ) {
case V_32 :
V_20 . V_33 = ( V_30 << 8 ) | V_34 ;
F_13 ( V_5 , & V_20 ) ;
break;
case V_35 :
V_20 . V_36 . V_37 = V_38 ;
V_20 . V_36 . V_39 = V_40 ;
V_20 . V_36 . time = V_30 ;
F_13 ( V_5 , & V_20 ) ;
break;
}
V_5 -> V_16 = V_30 ;
}
return 0 ;
}
void
F_23 ( struct V_1 * V_5 , struct V_41 * V_42 )
{
F_24 ( V_42 , L_3 ,
( F_10 ( & V_5 -> V_12 ) ? L_4 : L_5 ) ,
V_5 -> V_9 , V_5 -> V_16 ) ;
}

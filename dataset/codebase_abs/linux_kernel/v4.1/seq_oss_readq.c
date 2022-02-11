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
if ( F_9 ( & V_5 -> V_11 ) )
F_10 ( & V_5 -> V_11 ) ;
V_5 -> V_15 = ( unsigned long ) - 1 ;
}
int
F_11 ( struct V_1 * V_5 , int V_16 , unsigned char * V_17 , int V_18 )
{
union V_7 V_19 ;
int V_20 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_21 [ 0 ] = V_22 ;
V_19 . V_21 [ 2 ] = V_16 ;
while ( V_18 -- > 0 ) {
V_19 . V_21 [ 1 ] = * V_17 ++ ;
V_20 = F_12 ( V_5 , & V_19 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
int
F_12 ( struct V_1 * V_5 , union V_7 * V_23 )
{
unsigned long V_24 ;
F_13 ( & V_5 -> V_12 , V_24 ) ;
if ( V_5 -> V_8 >= V_5 -> V_4 - 1 ) {
F_14 ( & V_5 -> V_12 , V_24 ) ;
return - V_25 ;
}
memcpy ( & V_5 -> V_5 [ V_5 -> V_10 ] , V_23 , sizeof( * V_23 ) ) ;
V_5 -> V_10 = ( V_5 -> V_10 + 1 ) % V_5 -> V_4 ;
V_5 -> V_8 ++ ;
if ( F_9 ( & V_5 -> V_11 ) )
F_10 ( & V_5 -> V_11 ) ;
F_14 ( & V_5 -> V_12 , V_24 ) ;
return 0 ;
}
int
F_15 ( struct V_1 * V_5 , union V_7 * V_19 )
{
if ( V_5 -> V_8 == 0 )
return - V_26 ;
memcpy ( V_19 , & V_5 -> V_5 [ V_5 -> V_9 ] , sizeof( * V_19 ) ) ;
return 0 ;
}
void
F_16 ( struct V_1 * V_5 )
{
F_17 ( V_5 -> V_11 ,
( V_5 -> V_8 > 0 || V_5 -> V_9 == V_5 -> V_10 ) ,
V_5 -> V_13 ) ;
}
void
F_18 ( struct V_1 * V_5 )
{
if ( V_5 -> V_8 > 0 ) {
V_5 -> V_9 = ( V_5 -> V_9 + 1 ) % V_5 -> V_4 ;
V_5 -> V_8 -- ;
}
}
unsigned int
F_19 ( struct V_1 * V_5 , struct V_27 * V_27 , T_1 * V_28 )
{
F_20 ( V_27 , & V_5 -> V_11 , V_28 ) ;
return V_5 -> V_8 ;
}
int
F_21 ( struct V_1 * V_5 , unsigned long V_29 , int V_30 )
{
if ( V_29 != V_5 -> V_15 ) {
union V_7 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
switch ( V_30 ) {
case V_31 :
V_19 . V_32 = ( V_29 << 8 ) | V_33 ;
F_12 ( V_5 , & V_19 ) ;
break;
case V_34 :
V_19 . V_35 . V_36 = V_37 ;
V_19 . V_35 . V_38 = V_39 ;
V_19 . V_35 . time = V_29 ;
F_12 ( V_5 , & V_19 ) ;
break;
}
V_5 -> V_15 = V_29 ;
}
return 0 ;
}
void
F_22 ( struct V_1 * V_5 , struct V_40 * V_41 )
{
F_23 ( V_41 , L_1 ,
( F_9 ( & V_5 -> V_11 ) ? L_2 : L_3 ) ,
V_5 -> V_8 , V_5 -> V_15 ) ;
}

static int
F_1 ( T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
for ( V_5 = 0 , V_8 = V_3 ; V_5 < V_2 ; V_5 ++ ) {
V_6 = V_5 / 8 ;
V_7 = V_5 % 8 ;
if ( V_1 [ V_6 ] & ( ( T_1 ) 1 << V_7 ) ) {
V_8 = V_3 ;
continue;
}
if ( ! ( -- V_8 ) )
break;
}
if ( V_5 >= V_2 ) {
return - V_9 ;
}
for ( V_8 = V_3 ; V_8 > 0 ; V_8 -- ) {
V_6 = V_5 / 8 ;
V_7 = V_5 % 8 ;
V_1 [ V_6 ] |= ( ( T_1 ) 1 << V_7 ) ;
V_5 -- ;
}
* V_4 = V_5 + 1 ;
return 0 ;
}
static int F_2 ( T_1 * V_1 , unsigned int V_3 , unsigned int V_10 )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
for ( V_8 = V_3 , V_5 = V_10 ; V_8 > 0 ; V_8 -- ) {
V_6 = V_5 / 8 ;
V_7 = V_5 % 8 ;
V_1 [ V_6 ] &= ~ ( ( T_1 ) 1 << V_7 ) ;
V_5 ++ ;
}
return 0 ;
}
int F_3 ( struct V_11 * V_12 , unsigned int V_8 , unsigned int * V_4 )
{
int V_13 ;
if ( V_8 > V_12 -> V_14 )
return - V_9 ;
V_13 = F_1 ( V_12 -> V_1 , V_12 -> V_2 , V_8 , V_4 ) ;
if ( ! V_13 )
V_12 -> V_14 -= V_8 ;
return V_13 ;
}
int F_4 ( struct V_11 * V_12 , unsigned int V_8 , unsigned int V_10 )
{
F_2 ( V_12 -> V_1 , V_8 , V_10 ) ;
V_12 -> V_14 += V_8 ;
return 0 ;
}
static int F_5 ( const struct V_15 * V_15 )
{
return V_15 -> V_16 ;
}
static int F_6 ( const struct V_15 * V_15 )
{
return ( V_15 -> V_16 << 4 ) + V_17 [ V_15 -> type ] ;
}
static int F_7 ( struct V_15 * V_15 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; ( V_5 < 8 ) && ( ! ( V_15 -> V_18 & ( 0x1 << V_5 ) ) ) ; )
V_5 ++ ;
V_15 -> V_16 += ( V_19 >> V_5 ) ;
return V_15 -> V_16 ;
}
static int F_8 ( struct V_15 * V_15 )
{
return V_15 -> V_16 = V_15 -> V_10 ;
}
int
F_9 ( struct V_15 * V_15 , T_2 V_10 , enum V_20 type , T_2 V_18 , struct V_21 * V_21 )
{
int V_13 = 0 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_16 = V_10 ;
V_15 -> type = type ;
V_15 -> V_18 = V_18 ;
V_15 -> V_21 = V_21 ;
V_15 -> V_22 = & V_23 ;
if ( ! V_21 ) {
V_15 -> V_24 = NULL ;
return 0 ;
}
switch ( type ) {
case V_25 :
V_13 = V_21 -> V_26 ( & V_15 -> V_24 ) ;
break;
case V_27 :
V_13 = V_21 -> V_28 ( & V_15 -> V_24 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
break;
default:
F_10 ( ( (struct V_21 * ) V_21 ) -> V_32 -> V_33 ,
L_1 , type ) ;
return - V_34 ;
}
if ( V_13 ) {
F_10 ( ( (struct V_21 * ) V_21 ) -> V_32 -> V_33 ,
L_2 ) ;
return V_13 ;
}
return 0 ;
}
int F_11 ( struct V_15 * V_15 )
{
if ( ( NULL != V_15 -> V_21 ) && ( NULL != V_15 -> V_24 ) ) {
switch ( V_15 -> type ) {
case V_25 :
V_15 -> V_21 -> V_35 ( V_15 -> V_24 ) ;
break;
case V_27 :
V_15 -> V_21 -> V_36 ( V_15 -> V_24 ) ;
break;
case V_30 :
case V_31 :
break;
default:
F_10 ( ( (struct V_21 * ) V_15 -> V_21 ) -> V_32 -> V_33 ,
L_1 ,
V_15 -> type ) ;
break;
}
V_15 -> V_21 = V_15 -> V_24 = NULL ;
}
V_15 -> V_10 = V_15 -> V_16 = 0 ;
V_15 -> type = V_37 ;
V_15 -> V_18 = 0 ;
return 0 ;
}
int F_12 ( struct V_11 * V_12 , enum V_20 type ,
unsigned int V_2 , struct V_21 * V_21 )
{
int V_13 = 0 ;
V_12 -> type = V_37 ;
V_12 -> V_1 = F_13 ( ( ( V_2 + 8 - 1 ) / 8 ) , V_38 ) ;
if ( ! V_12 -> V_1 )
return - V_39 ;
switch ( type ) {
case V_25 :
V_13 = V_21 -> V_40 ( & V_12 -> V_24 ) ;
break;
case V_29 :
V_13 = V_21 -> V_41 ( & V_12 -> V_24 ) ;
break;
case V_27 :
V_13 = V_21 -> V_42 ( & V_12 -> V_24 ) ;
break;
case V_31 :
V_13 = V_21 -> V_43 ( V_21 , & V_12 -> V_24 ) ;
break;
case V_30 :
break;
default:
F_10 ( V_21 -> V_32 -> V_33 ,
L_1 , type ) ;
V_13 = - V_34 ;
goto error;
}
if ( V_13 ) {
F_10 ( V_21 -> V_32 -> V_33 ,
L_3 ) ;
goto error;
}
V_12 -> type = type ;
V_12 -> V_14 = V_12 -> V_2 = V_2 ;
V_12 -> V_21 = V_21 ;
return 0 ;
error:
F_14 ( V_12 -> V_1 ) ;
return V_13 ;
}
int F_15 ( struct V_11 * V_12 )
{
if ( NULL != V_12 -> V_1 ) {
F_14 ( V_12 -> V_1 ) ;
V_12 -> V_1 = NULL ;
}
if ( ( NULL != V_12 -> V_21 ) && ( NULL != V_12 -> V_24 ) ) {
switch ( V_12 -> type ) {
case V_25 :
V_12 -> V_21 -> V_44 ( V_12 -> V_24 ) ;
break;
case V_29 :
V_12 -> V_21 -> V_45 ( V_12 -> V_24 ) ;
break;
case V_27 :
V_12 -> V_21 -> V_46 ( V_12 -> V_24 ) ;
break;
case V_31 :
V_12 -> V_21 -> V_47 ( V_12 -> V_24 ) ;
break;
case V_30 :
break;
default:
F_10 ( ( (struct V_21 * ) V_12 -> V_21 ) -> V_32 -> V_33 ,
L_1 ,
V_12 -> type ) ;
break;
}
V_12 -> V_21 = V_12 -> V_24 = NULL ;
}
V_12 -> type = V_37 ;
V_12 -> V_14 = V_12 -> V_2 = 0 ;
return 0 ;
}

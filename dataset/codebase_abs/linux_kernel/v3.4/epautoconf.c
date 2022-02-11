static int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8
)
{
T_1 type ;
const char * V_9 ;
T_2 V_10 ;
int V_11 = 0 ;
if ( NULL != V_4 -> V_12 )
return 0 ;
type = V_6 -> V_13 & V_14 ;
if ( V_15 == type )
return 0 ;
if ( 'e' != V_4 -> V_16 [ 0 ] )
return 0 ;
if ( '-' != V_4 -> V_16 [ 2 ] ) {
V_9 = strrchr ( V_4 -> V_16 , '-' ) ;
if ( V_9 ) {
switch ( type ) {
case V_17 :
if ( 's' == V_9 [ 2 ] )
return 0 ;
if ( F_2 ( V_2 )
&& 'i' == V_9 [ 1 ] )
return 0 ;
break;
case V_18 :
if ( 'b' != V_9 [ 1 ] )
return 0 ;
break;
case V_19 :
if ( 's' != V_9 [ 2 ] )
return 0 ;
}
} else {
V_9 = V_4 -> V_16 + strlen ( V_4 -> V_16 ) ;
}
V_9 -- ;
if ( ! isdigit ( * V_9 ) ) {
if ( V_6 -> V_20 & V_21 ) {
if ( 'n' != * V_9 )
return 0 ;
} else {
if ( 't' != * V_9 )
return 0 ;
}
}
}
if ( F_3 ( V_6 ) ) {
if ( V_8 && V_2 -> V_22 >= V_23 ) {
V_11 = V_8 -> V_13 & 0x1f ;
if ( V_11 > V_4 -> V_24 )
return 0 ;
}
}
if ( V_6 -> V_25 == 0 )
V_6 -> V_25 = F_4 ( V_4 -> V_26 ) ;
V_10 = 0x7ff & F_5 ( V_6 ) ;
switch ( type ) {
case V_17 :
if ( ! F_6 ( V_2 ) && V_10 > 64 )
return 0 ;
case V_19 :
if ( V_4 -> V_26 < V_10 )
return 0 ;
if ( ! F_6 ( V_2 ) && V_10 > 1023 )
return 0 ;
if ( ( V_6 -> V_25 & F_4 ( 3 << 11 ) ) ) {
if ( ! F_6 ( V_2 ) )
return 0 ;
}
break;
}
V_6 -> V_20 &= V_21 ;
if ( isdigit ( V_4 -> V_16 [ 2 ] ) ) {
T_1 V_27 = F_7 ( & V_4 -> V_16 [ 2 ] , NULL , 10 ) ;
V_6 -> V_20 |= V_27 ;
#ifdef F_8
} else if ( V_6 -> V_20 & V_21 ) {
if ( ++ V_28 > 15 )
return 0 ;
V_6 -> V_20 = V_21 | V_28 ;
#endif
} else {
if ( ++ V_29 > 15 )
return 0 ;
V_6 -> V_20 |= V_29 ;
}
if ( ( V_18 == type ) && ! V_8 ) {
int V_30 = V_4 -> V_26 ;
if ( V_30 > 64 )
V_30 = 64 ;
V_6 -> V_25 = F_4 ( V_30 ) ;
}
V_4 -> V_31 = V_6 -> V_20 ;
return 1 ;
}
static struct V_3 *
F_9 ( struct V_1 * V_2 , const char * V_16 )
{
struct V_3 * V_4 ;
F_10 (ep, &gadget->ep_list, ep_list) {
if ( 0 == strcmp ( V_4 -> V_16 , V_16 ) )
return V_4 ;
}
return NULL ;
}
struct V_3 * F_11 (
struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8
)
{
struct V_3 * V_4 ;
T_1 type ;
type = V_6 -> V_13 & V_14 ;
if ( F_12 ( V_2 ) && type == V_17 ) {
V_4 = F_9 ( V_2 , L_1 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 , V_8 ) )
goto V_32;
V_4 = F_9 ( V_2 , L_2 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 , V_8 ) )
goto V_32;
} else if ( F_13 ( V_2 ) ) {
if ( V_17 == type ) {
V_4 = F_9 ( V_2 , L_3 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 , V_8 ) )
goto V_32;
} else if ( V_18 == type
&& ( V_21 & V_6 -> V_20 ) ) {
V_4 = F_9 ( V_2 , L_4 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ,
V_8 ) )
goto V_32;
}
#ifdef F_14
} else if ( F_15 ( V_2 ) ) {
if ( ( V_18 == type ) ||
( V_19 == type ) ) {
if ( V_21 & V_6 -> V_20 )
V_4 = F_9 ( V_2 , L_5 ) ;
else
V_4 = F_9 ( V_2 , L_6 ) ;
} else if ( V_17 == type ) {
if ( V_21 & V_6 -> V_20 )
V_4 = F_9 ( V_2 , L_7 ) ;
else
V_4 = F_9 ( V_2 , L_8 ) ;
} else
V_4 = NULL ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 , V_8 ) )
goto V_32;
#endif
}
F_10 (ep, &gadget->ep_list, ep_list) {
if ( F_1 ( V_2 , V_4 , V_6 , V_8 ) )
goto V_32;
}
return NULL ;
V_32:
V_4 -> V_6 = NULL ;
V_4 -> V_33 = NULL ;
return V_4 ;
}
struct V_3 * F_16 (
struct V_1 * V_2 ,
struct V_5 * V_6
)
{
return F_11 ( V_2 , V_6 , NULL ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_10 (ep, &gadget->ep_list, ep_list) {
V_4 -> V_12 = NULL ;
}
#ifdef F_8
V_28 = 0 ;
#endif
V_29 = 0 ;
}

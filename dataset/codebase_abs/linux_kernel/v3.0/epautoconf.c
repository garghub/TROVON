static int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6
)
{
T_1 type ;
const char * V_7 ;
T_2 V_8 ;
if ( NULL != V_4 -> V_9 )
return 0 ;
type = V_6 -> V_10 & V_11 ;
if ( V_12 == type )
return 0 ;
if ( 'e' != V_4 -> V_13 [ 0 ] )
return 0 ;
if ( '-' != V_4 -> V_13 [ 2 ] ) {
V_7 = strrchr ( V_4 -> V_13 , '-' ) ;
if ( V_7 ) {
switch ( type ) {
case V_14 :
if ( 's' == V_7 [ 2 ] )
return 0 ;
if ( F_2 ( V_2 )
&& 'i' == V_7 [ 1 ] )
return 0 ;
break;
case V_15 :
if ( 'b' != V_7 [ 1 ] )
return 0 ;
break;
case V_16 :
if ( 's' != V_7 [ 2 ] )
return 0 ;
}
} else {
V_7 = V_4 -> V_13 + strlen ( V_4 -> V_13 ) ;
}
V_7 -- ;
if ( ! isdigit ( * V_7 ) ) {
if ( V_6 -> V_17 & V_18 ) {
if ( 'n' != * V_7 )
return 0 ;
} else {
if ( 't' != * V_7 )
return 0 ;
}
}
}
if ( V_6 -> V_19 == 0 )
V_6 -> V_19 = F_3 ( V_4 -> V_20 ) ;
V_8 = 0x7ff & F_4 ( V_6 -> V_19 ) ;
switch ( type ) {
case V_14 :
if ( ! V_2 -> V_21 && V_8 > 64 )
return 0 ;
case V_16 :
if ( V_4 -> V_20 < V_8 )
return 0 ;
if ( ! V_2 -> V_21 && V_8 > 1023 )
return 0 ;
if ( ( V_6 -> V_19 & F_3 ( 3 << 11 ) ) ) {
if ( ! V_2 -> V_21 )
return 0 ;
}
break;
}
V_6 -> V_17 &= V_18 ;
if ( isdigit ( V_4 -> V_13 [ 2 ] ) ) {
T_1 V_22 = F_5 ( & V_4 -> V_13 [ 2 ] , NULL , 10 ) ;
V_6 -> V_17 |= V_22 ;
#ifdef F_6
} else if ( V_6 -> V_17 & V_18 ) {
if ( ++ V_23 > 15 )
return 0 ;
V_6 -> V_17 = V_18 | V_23 ;
#endif
} else {
if ( ++ V_24 > 15 )
return 0 ;
V_6 -> V_17 |= V_24 ;
}
if ( V_15 == type ) {
int V_25 = V_4 -> V_20 ;
if ( V_25 > 64 )
V_25 = 64 ;
V_6 -> V_19 = F_3 ( V_25 ) ;
}
return 1 ;
}
static struct V_3 *
F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_3 * V_4 ;
F_8 (ep, &gadget->ep_list, ep_list) {
if ( 0 == strcmp ( V_4 -> V_13 , V_13 ) )
return V_4 ;
}
return NULL ;
}
struct V_3 * F_9 (
struct V_1 * V_2 ,
struct V_5 * V_6
)
{
struct V_3 * V_4 ;
T_1 type ;
type = V_6 -> V_10 & V_11 ;
if ( F_10 ( V_2 ) && type == V_14 ) {
V_4 = F_7 ( V_2 , L_1 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
V_4 = F_7 ( V_2 , L_2 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
} else if ( F_11 ( V_2 ) ) {
if ( V_14 == type ) {
V_4 = F_7 ( V_2 , L_3 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
} else if ( V_15 == type
&& ( V_18 & V_6 -> V_17 ) ) {
V_4 = F_7 ( V_2 , L_4 ) ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
}
#ifdef F_12
} else if ( F_13 ( V_2 ) ) {
if ( ( V_15 == type ) ||
( V_16 == type ) ) {
if ( V_18 & V_6 -> V_17 )
V_4 = F_7 ( V_2 , L_5 ) ;
else
V_4 = F_7 ( V_2 , L_6 ) ;
} else if ( V_14 == type ) {
if ( V_18 & V_6 -> V_17 )
V_4 = F_7 ( V_2 , L_7 ) ;
else
V_4 = F_7 ( V_2 , L_8 ) ;
} else
V_4 = NULL ;
if ( V_4 && F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
#endif
}
F_8 (ep, &gadget->ep_list, ep_list) {
if ( F_1 ( V_2 , V_4 , V_6 ) )
return V_4 ;
}
return NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_8 (ep, &gadget->ep_list, ep_list) {
V_4 -> V_9 = NULL ;
}
#ifdef F_6
V_23 = 0 ;
#endif
V_24 = 0 ;
}

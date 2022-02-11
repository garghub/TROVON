unsigned int F_1 ( const unsigned int V_1 )
{
T_1 * V_2 = F_2 () ;
T_2 * V_3 ;
unsigned int V_4 , V_5 , V_6 ;
struct V_7 V_8 ;
V_5 = F_3 ( V_1 ) ;
if ( V_9 == V_5 )
return 0 ;
V_8 . V_10 = F_4 ( V_1 ) ;
V_8 . V_11 = F_5 ( V_1 ) ;
V_8 . V_12 = 0 ;
if ( F_6 ( V_1 ) )
V_4 = V_5 ;
else
V_4 = V_2 -> V_13 [ F_7 ( V_1 ) ] ;
if ( ! F_8 ( V_1 ) ) {
register unsigned int V_14 = F_9 ( V_1 ) ;
if ( V_4 < V_2 -> V_13 [ V_14 ] ) {
V_4 = V_2 -> V_13 [ V_14 ] ;
}
}
V_3 = & V_2 -> V_15 [ F_10 ( V_1 ) ] ;
switch ( V_4 ) {
case V_16 :
V_6 = F_11 ( & V_8 , V_1 , V_3 ) ;
break;
case V_17 :
V_6 = F_12 ( & V_8 , V_1 , V_3 ) ;
break;
#ifdef F_13
case V_18 :
V_6 = F_14 ( & V_8 , V_1 , V_3 ) ;
break;
#endif
default:
V_6 = 0 ;
}
if ( V_6 != 0 ) {
V_2 -> V_13 [ F_10 ( V_1 ) ] = V_5 ;
#ifdef F_13
if ( V_5 != V_4 ) {
switch ( V_5 ) {
case V_16 :
{
if ( V_17 == V_4 )
V_3 -> V_19 = F_15 ( & V_8 , V_3 -> V_20 ) ;
else
V_3 -> V_19 = F_16 ( & V_8 , V_3 -> V_21 ) ;
}
break;
case V_17 :
{
if ( V_16 == V_4 )
V_3 -> V_20 = F_17 ( V_3 -> V_19 ) ;
else
V_3 -> V_20 = F_18 ( & V_8 , V_3 -> V_21 ) ;
}
break;
case V_18 :
{
if ( V_16 == V_4 )
V_3 -> V_21 = F_19 ( V_3 -> V_19 ) ;
else
V_3 -> V_21 = F_20 ( V_3 -> V_20 ) ;
}
break;
}
}
#else
if ( V_5 != V_4 ) {
if ( V_5 == V_16 )
V_3 -> V_19 = F_15 ( & V_8 , V_3 -> V_20 ) ;
else
V_3 -> V_20 = F_17 ( V_3 -> V_19 ) ;
}
#endif
}
if ( V_8 . V_12 )
F_21 ( V_8 . V_12 ) ;
return V_6 ;
}

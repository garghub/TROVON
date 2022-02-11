const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
default: return L_5 ;
}
}
int F_2 ( const struct V_6 * V_7 , int V_8 )
{
if ( ( V_9 ) V_8 >= V_7 -> V_10 )
return 0 ;
switch ( V_7 -> V_1 ) {
case V_2 :
return ( (struct V_11 * ) V_7 ) -> V_12 ;
case V_3 :
return ( (struct V_13 * ) V_7 ) -> V_14 [ V_8 ] ;
case V_4 :
return ( (struct V_15 * ) V_7 ) -> V_16 [ F_3 ( V_8 ) ] ;
case V_5 :
return ( (struct V_17 * ) V_7 ) -> V_14 [ V_8 ] ;
}
return 0 ;
}
void F_4 ( struct V_11 * V_7 )
{
F_5 ( V_7 -> V_18 . V_19 ) ;
F_5 ( V_7 -> V_18 . V_20 ) ;
F_5 ( V_7 ) ;
}
void F_6 ( struct V_13 * V_7 )
{
F_5 ( V_7 -> V_14 ) ;
F_5 ( V_7 -> V_21 ) ;
F_5 ( V_7 -> V_18 . V_19 ) ;
F_5 ( V_7 -> V_18 . V_20 ) ;
F_5 ( V_7 ) ;
}
void F_7 ( struct V_15 * V_7 )
{
F_5 ( V_7 -> V_18 . V_19 ) ;
F_5 ( V_7 -> V_18 . V_20 ) ;
F_5 ( V_7 -> V_16 ) ;
F_5 ( V_7 ) ;
}
void F_8 ( struct V_17 * V_7 )
{
F_5 ( V_7 -> V_22 ) ;
F_5 ( V_7 -> V_14 ) ;
F_5 ( V_7 -> V_18 . V_19 ) ;
F_5 ( V_7 -> V_18 . V_20 ) ;
F_5 ( V_7 ) ;
}
void F_9 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_1 ) {
case V_2 :
F_4 ( (struct V_11 * ) V_7 ) ;
break;
case V_3 :
F_6 ( (struct V_13 * ) V_7 ) ;
break;
case V_4 :
F_7 ( (struct V_15 * ) V_7 ) ;
break;
case V_5 :
F_8 ( (struct V_17 * ) V_7 ) ;
break;
}
}
void F_10 ( struct V_23 * V_24 )
{
if ( V_24 -> V_25 ) {
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_24 -> V_26 ; V_7 ++ ) {
if ( V_24 -> V_25 [ V_7 ] == NULL )
continue;
F_9 ( V_24 -> V_25 [ V_7 ] ) ;
}
F_5 ( V_24 -> V_25 ) ;
}
if ( V_24 -> V_27 ) {
V_9 V_7 ;
for ( V_7 = 0 ; V_7 < V_24 -> V_28 ; V_7 ++ )
F_5 ( V_24 -> V_27 [ V_7 ] ) ;
F_5 ( V_24 -> V_27 ) ;
}
F_5 ( V_24 ) ;
}

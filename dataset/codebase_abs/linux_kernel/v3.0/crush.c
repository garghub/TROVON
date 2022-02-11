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
int F_2 ( struct V_6 * V_7 , int V_8 )
{
if ( V_8 >= V_7 -> V_9 )
return 0 ;
switch ( V_7 -> V_1 ) {
case V_2 :
return ( (struct V_10 * ) V_7 ) -> V_11 ;
case V_3 :
return ( (struct V_12 * ) V_7 ) -> V_13 [ V_8 ] ;
case V_4 :
if ( V_8 & 1 )
return ( (struct V_14 * ) V_7 ) -> V_15 [ V_8 ] ;
return 0 ;
case V_5 :
return ( (struct V_16 * ) V_7 ) -> V_13 [ V_8 ] ;
}
return 0 ;
}
void F_3 ( struct V_17 * V_18 )
{
int V_19 , V_7 , V_20 ;
for ( V_7 = 0 ; V_7 < V_18 -> V_21 ; V_7 ++ ) {
if ( V_18 -> V_22 [ V_7 ] == NULL )
continue;
for ( V_19 = 0 ; V_19 < V_18 -> V_22 [ V_7 ] -> V_9 ; V_19 ++ ) {
V_20 = V_18 -> V_22 [ V_7 ] -> V_23 [ V_19 ] ;
F_4 ( V_20 >= V_18 -> V_24 ||
V_20 < - V_18 -> V_21 ) ;
if ( V_20 >= 0 )
V_18 -> V_25 [ V_20 ] = V_18 -> V_22 [ V_7 ] -> V_26 ;
else
V_18 -> V_27 [ - 1 - V_20 ] = V_18 -> V_22 [ V_7 ] -> V_26 ;
}
}
}
void F_5 ( struct V_10 * V_7 )
{
F_6 ( V_7 -> V_28 . V_29 ) ;
F_6 ( V_7 -> V_28 . V_23 ) ;
F_6 ( V_7 ) ;
}
void F_7 ( struct V_12 * V_7 )
{
F_6 ( V_7 -> V_13 ) ;
F_6 ( V_7 -> V_30 ) ;
F_6 ( V_7 -> V_28 . V_29 ) ;
F_6 ( V_7 -> V_28 . V_23 ) ;
F_6 ( V_7 ) ;
}
void F_8 ( struct V_14 * V_7 )
{
F_6 ( V_7 -> V_15 ) ;
F_6 ( V_7 ) ;
}
void F_9 ( struct V_16 * V_7 )
{
F_6 ( V_7 -> V_31 ) ;
F_6 ( V_7 -> V_13 ) ;
F_6 ( V_7 -> V_28 . V_29 ) ;
F_6 ( V_7 -> V_28 . V_23 ) ;
F_6 ( V_7 ) ;
}
void F_10 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_1 ) {
case V_2 :
F_5 ( (struct V_10 * ) V_7 ) ;
break;
case V_3 :
F_7 ( (struct V_12 * ) V_7 ) ;
break;
case V_4 :
F_8 ( (struct V_14 * ) V_7 ) ;
break;
case V_5 :
F_9 ( (struct V_16 * ) V_7 ) ;
break;
}
}
void F_11 ( struct V_17 * V_18 )
{
int V_7 ;
if ( V_18 -> V_22 ) {
for ( V_7 = 0 ; V_7 < V_18 -> V_21 ; V_7 ++ ) {
if ( V_18 -> V_22 [ V_7 ] == NULL )
continue;
F_10 ( V_18 -> V_22 [ V_7 ] ) ;
}
F_6 ( V_18 -> V_22 ) ;
}
if ( V_18 -> V_32 ) {
for ( V_7 = 0 ; V_7 < V_18 -> V_33 ; V_7 ++ )
F_6 ( V_18 -> V_32 [ V_7 ] ) ;
F_6 ( V_18 -> V_32 ) ;
}
F_6 ( V_18 -> V_27 ) ;
F_6 ( V_18 -> V_25 ) ;
F_6 ( V_18 ) ;
}

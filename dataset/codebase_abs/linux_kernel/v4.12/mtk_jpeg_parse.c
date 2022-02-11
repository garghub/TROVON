static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return - 1 ;
return V_2 -> V_5 [ V_2 -> V_3 ++ ] ;
}
static int F_2 ( struct V_1 * V_2 , T_1 * V_6 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 == - 1 )
return - 1 ;
V_7 = V_8 << 8 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 == - 1 )
return - 1 ;
* V_6 = ( T_1 ) V_8 | V_7 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , long V_9 )
{
if ( V_9 <= 0 )
return;
while ( V_9 -- )
F_1 ( V_2 ) ;
}
static bool F_4 ( struct V_10 * V_11 , T_2 * V_12 ,
T_1 V_13 )
{
bool V_14 = true ;
struct V_1 V_2 ;
V_2 . V_5 = V_12 ;
V_2 . V_4 = V_13 ;
V_2 . V_3 = 0 ;
while ( V_14 ) {
int V_15 , V_16 , V_8 ;
T_1 V_6 ;
V_8 = F_1 ( & V_2 ) ;
if ( V_8 == - 1 )
return false ;
if ( V_8 != 0xff )
continue;
do
V_8 = F_1 ( & V_2 ) ;
while ( V_8 == 0xff );
if ( V_8 == - 1 )
return false ;
if ( V_8 == 0 )
continue;
V_16 = 0 ;
switch ( V_8 ) {
case V_17 :
if ( F_2 ( & V_2 , & V_6 ) )
break;
if ( F_1 ( & V_2 ) == - 1 )
break;
if ( F_2 ( & V_2 , & V_6 ) )
break;
V_11 -> V_18 = V_6 ;
if ( F_2 ( & V_2 , & V_6 ) )
break;
V_11 -> V_19 = V_6 ;
V_11 -> V_20 = F_1 ( & V_2 ) ;
if ( V_11 -> V_20 != 1 && V_11 -> V_20 != 3 )
break;
for ( V_15 = 0 ; V_15 < V_11 -> V_20 ; V_15 ++ ) {
V_11 -> V_21 [ V_15 ] = F_1 ( & V_2 ) ;
if ( V_11 -> V_21 [ V_15 ] == - 1 )
break;
V_8 = F_1 ( & V_2 ) ;
if ( V_8 == - 1 )
break;
V_11 -> V_22 [ V_15 ] = ( V_8 >> 4 ) & 0x0F ;
V_11 -> V_23 [ V_15 ] = V_8 & 0x0F ;
V_11 -> V_24 [ V_15 ] = F_1 ( & V_2 ) ;
if ( V_11 -> V_24 [ V_15 ] == - 1 )
break;
}
V_14 = ! ( V_15 == V_11 -> V_20 ) ;
break;
case V_25 ... V_25 + 7 :
case V_26 :
case V_27 :
case V_28 :
break;
default:
if ( F_2 ( & V_2 , & V_6 ) )
break;
V_16 = ( long ) V_6 - 2 ;
F_3 ( & V_2 , V_16 ) ;
break;
}
}
return ! V_14 ;
}
bool F_5 ( struct V_10 * V_11 , T_2 * V_12 ,
T_1 V_13 )
{
if ( ! F_4 ( V_11 , V_12 , V_13 ) )
return false ;
if ( F_6 ( V_11 ) )
return false ;
return true ;
}

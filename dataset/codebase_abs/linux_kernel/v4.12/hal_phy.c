T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
for ( V_2 = 0 ; V_2 <= 31 ; V_2 ++ ) {
if ( ( ( V_1 >> V_2 ) & 0x1 ) == 1 )
break;
}
return V_2 ;
}
T_1 F_2 ( T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 )
{
return V_6 [ V_4 ] [ V_5 ] . V_7 ;
}
void F_3 (
T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 , T_2 T_1 V_8
)
{
V_6 [ V_4 ] [ V_5 ] . V_7 = ( V_8 & V_9 ) ;
V_6 [ V_4 ] [ V_5 ] . V_10 = true ;
}
bool F_4 ( T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 )
{
T_1 V_11 ;
if ( V_6 [ V_4 ] [ V_5 ] . V_12 == true ) {
V_11 = F_5 ( V_3 , V_4 , V_5 , V_9 ) ;
if ( V_6 [ V_4 ] [ V_5 ] . V_7 != V_11 ) {
V_6 [ V_4 ] [ V_5 ] . V_13 = true ;
}
return V_6 [ V_4 ] [ V_5 ] . V_13 ;
}
return false ;
}
void F_6 ( T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 )
{
if ( V_6 [ V_4 ] [ V_5 ] . V_13 == true ) {
if ( V_6 [ V_4 ] [ V_5 ] . V_14 == true ) {
F_7 ( V_3 , V_4 , V_5 , V_9 ,
V_6 [ V_4 ] [ V_5 ] . V_7 ) ;
}
}
}
void F_8 ( T_2 T_3 V_3 )
{
T_4 V_4 = 0 ;
T_1 V_5 = 0 , V_15 = F_9 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
F_4 ( V_3 , V_4 , V_5 ) ;
}
}
}
void F_10 ( T_2 T_3 V_3 )
{
T_4 V_4 = 0 ;
T_1 V_5 = 0 , V_15 = F_9 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
F_6 ( V_3 , V_4 , V_5 ) ;
}
}
}
void
F_11 (
T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 , T_2 T_4 Type
)
{
V_6 [ V_4 ] [ V_5 ] . V_12 = Type ;
}
void F_12 (
T_2 T_3 V_3 , T_2 T_4 V_4 , T_2 T_1 V_5 , T_2 T_4 Type
)
{
V_6 [ V_4 ] [ V_5 ] . V_14 = Type ;
}
void F_13 ( T_2 T_3 V_3 )
{
T_4 V_4 = 0 ;
T_1 V_5 = 0 , V_15 = F_9 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_5 != 0x26 && V_5 != 0x27 )
F_11 ( V_3 , V_4 , V_5 , false ) ;
else
F_11 ( V_3 , V_4 , V_5 , true ) ;
}
}
}
void F_14 ( T_2 T_3 V_3 )
{
T_4 V_4 = 0 ;
T_1 V_5 = 0 , V_15 = F_9 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_5 != 0x26 && V_5 != 0x27 )
F_12 ( V_3 , V_4 , V_5 , false ) ;
else
F_12 ( V_3 , V_4 , V_5 , true ) ;
}
}
}
void F_15 ( T_2 T_3 V_3 )
{
T_4 V_4 = 0 ;
T_1 V_5 = 0 , V_15 = F_9 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_6 [ V_4 ] [ V_5 ] . V_7 = 0 ;
V_6 [ V_4 ] [ V_5 ] . V_12 = false ;
V_6 [ V_4 ] [ V_5 ] . V_14 = false ;
V_6 [ V_4 ] [ V_5 ] . V_13 = false ;
V_6 [ V_4 ] [ V_5 ] . V_10 = false ;
}
}
}

void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 )
{
int V_5 , V_6 ;
while ( V_4 > 0 ) {
V_5 = F_2 ( V_1 , V_3 ) ;
V_4 -- ;
if ( V_4 <= 0 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_1 ) ;
return;
}
if ( V_5 > V_4 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_2 ,
V_5 , V_4 ) ;
return;
}
if ( V_2 ) {
T_3 * V_7 ;
F_4 ( V_1 , V_3 , V_5 + 1 ) ;
V_7 = F_5 ( V_2 , V_1 , V_3 , V_5 + 1 ,
L_3 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_6 ( V_7 , L_4 ,
F_2 ( V_1 , V_3 + V_6 + 1 ) ) ;
if ( ( ( V_6 & 1 ) == 0 ) &&
( V_6 + 1 < V_5 ) ) {
F_6 ( V_7 , L_5 ) ;
}
}
}
V_3 += V_5 + 1 ;
V_4 -= V_5 ;
}
}
void
F_7 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 )
{
T_4 V_8 ;
int V_9 ;
T_3 * V_7 ;
if ( V_4 <= 0 ) {
return;
}
V_8 = F_2 ( V_1 , V_3 ) ;
V_3 += 1 ;
V_4 -- ;
V_9 = FALSE ;
switch ( V_8 ) {
case 1 :
V_7 = F_5 ( V_2 , V_1 , V_3 - 1 , V_4 + 1 ,
L_6 , V_4 ) ;
if ( V_4 > 0 ) {
F_6 ( V_7 , L_7 ,
F_8 ( V_1 , V_3 , V_4 ) ) ;
} else {
F_6 ( V_7 , L_8 ) ;
}
break;
case 54 :
V_7 = F_5 ( V_2 , V_1 , V_3 - 1 , V_4 + 1 ,
L_9 , V_4 ) ;
if ( V_4 == 16 ) {
F_6 ( V_7 , L_10 , F_2 ( V_1 , V_3 ) ) ;
V_3 += 1 ;
V_4 -- ;
while ( V_4 > 0 ) {
F_6 ( V_7 , L_4 , F_2 ( V_1 , V_3 ) ) ;
V_3 += 1 ;
V_4 -- ;
}
} else {
F_6 ( V_7 ,
L_11 ) ;
}
break;
default:
F_5 ( V_2 , V_1 , V_3 - 1 , V_4 + 1 ,
L_12 , V_8 , V_4 ) ;
V_9 = TRUE ;
break;
}
if ( V_9 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_13 ) ;
}
}
void
F_9 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 )
{
if ( ! V_2 ) return;
if ( V_4 != 0 ) {
F_5 ( V_2 , V_1 , V_3 , V_4 ,
L_14 , V_4 ,
F_10 ( F_11 () , V_1 , V_3 , V_4 ) ) ;
}
}
void
F_12 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 , int V_10 )
{
if ( ! V_2 ) return;
if ( V_4 == 0 ) {
F_5 ( V_2 , V_1 , V_3 , V_4 ,
L_15 ) ;
} else {
const char * V_11 = F_10 ( F_11 () , V_1 , V_3 , V_4 ) ;
F_13 ( V_2 , V_10 ,
V_1 , V_3 , V_4 ,
V_11 , L_16 , V_4 , V_11 ) ;
}
}
void
F_14 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 ,
int V_10 )
{
T_5 V_12 ;
const char * V_13 ;
while ( V_4 > 0 ) {
if ( V_4 != 1 ) {
V_12 = F_15 ( V_1 , V_3 ) ;
switch( V_12 & 0x0fff ) {
case 0 :
V_13 = L_17 ;
break;
case 1 :
V_13 = L_18 ;
break;
case 2 :
V_13 = L_19 ;
break;
case 3 :
V_13 = L_20 ;
break;
case 4095 :
V_13 = L_21 ;
break;
default:
V_13 = L_22 ;
break;
}
F_16 ( V_2 , V_10 , V_1 , V_3 , 2 ,
V_12 ,
L_23 ,
V_13 ,
V_12 & 0xfff ,
( V_12 & 0x8000 ) ? L_24 : L_25 ,
( V_12 & 0x4000 ) ? L_26 : L_24 ) ;
} else {
F_5 ( V_2 , V_1 , V_3 , 1 ,
L_27 ) ;
break;
}
V_4 = V_4 - 2 ;
V_3 = V_3 + 2 ;
}
}
void
F_17 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 , int V_10 )
{
if ( V_4 <= 0 ) {
return;
}
while ( V_4 > 0 ) {
if ( V_4 < 4 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_28 , V_4 ) ;
return;
}
if ( V_2 ) {
F_18 ( V_2 , V_10 , V_1 , V_3 , 4 , V_14 ) ;
}
V_3 += 4 ;
V_4 -= 4 ;
}
}
void
F_19 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 , int V_10 )
{
T_6 V_15 [ 16 ] ;
if ( V_4 <= 0 ) {
return;
}
while ( V_4 > 0 ) {
if ( V_4 < 16 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_29 , V_4 ) ;
return;
}
F_20 ( V_1 , V_15 , V_3 , sizeof( V_15 ) ) ;
if ( V_2 ) {
F_21 ( V_2 , V_10 , V_1 , V_3 , 16 , V_15 ) ;
}
V_3 += 16 ;
V_4 -= 16 ;
}
}
void
F_22 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
int V_4 , int V_10 )
{
if ( V_4 <= 0 ) {
return;
}
if ( V_4 != 4 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_30 , V_4 ) ;
return;
}
if ( V_2 ) {
F_18 ( V_2 , V_10 , V_1 , V_3 , 4 , V_14 ) ;
}
}
void
F_23 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 )
{
T_7 V_16 ;
T_3 * V_7 ;
if ( ! V_2 ) return;
F_4 ( V_1 , V_3 , V_4 ) ;
if ( V_4 <= 0 ) {
F_5 ( V_2 , V_1 , V_3 , V_4 ,
L_31 ) ;
} else {
V_16 = TRUE ;
V_7 = F_5 ( V_2 , V_1 , V_3 , V_4 ,
L_32 ) ;
while ( V_4 -- > 0 ) {
if ( ! V_16 ) {
F_6 ( V_7 , L_33 ) ;
}
F_6 ( V_7 , L_34 ,
( F_2 ( V_1 , V_3 ) == V_17
? L_35
: F_24 ( F_2 ( V_1 , V_3 ) , V_18 ,
L_36 ) ) ,
F_2 ( V_1 , V_3 ) ) ;
V_3 ++ ;
V_16 = FALSE ;
}
}
}
void
F_25 ( T_1 * V_1 , T_2 * V_2 , int V_3 ,
const T_8 * V_19 , int V_20 , int V_21 ,
int T_9 V_22 )
{
T_6 V_23 ;
T_6 V_4 ;
int V_24 ;
T_3 * V_7 ;
T_2 * V_25 ;
while ( V_20 > 0 ) {
V_23 = F_2 ( V_1 , V_3 ) ;
V_3 += 1 ;
V_20 -= 1 ;
if ( V_20 == 0 )
break;
V_4 = F_2 ( V_1 , V_3 ) ;
V_3 += 1 ;
V_20 -= 1 ;
if ( V_20 == 0 )
break;
if ( V_20 < V_4 ) {
F_3 ( V_1 , V_2 , V_3 ,
L_37 ,
V_4 , V_20 ) ;
return;
}
V_24 = 0 ;
while ( ( V_19 [ V_24 ] . V_26 != NULL ) && ( V_19 [ V_24 ] . V_27 != V_23 ) ) {
V_24 ++ ;
}
if ( V_19 [ V_24 ] . V_26 ) {
if ( V_2 ) {
V_7 = F_5 ( V_2 , V_1 , V_3 - 2 ,
V_4 + 2 , L_38 ,
V_19 [ V_24 ] . V_28 , V_4 ) ;
V_25 = F_26 ( V_7 ,
* V_19 [ V_24 ] . V_10 ) ;
} else {
V_25 = NULL ;
}
V_19 [ V_24 ] . V_26 ( V_1 , V_25 , V_3 ,
V_21 , V_4 ) ;
} else {
#if 0
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "Unknown code %u (%u)",
code, length);
clv_tree = proto_item_add_subtree(ti,
unknown_tree_id );
} else {
clv_tree = NULL;
}
#else
if ( V_2 ) {
F_5 ( V_2 , V_1 , V_3 - 2 ,
V_4 + 2 , L_39 ,
V_23 , V_4 ) ;
}
#endif
}
V_3 += V_4 ;
V_20 -= V_4 ;
}
}

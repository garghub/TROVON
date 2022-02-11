void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 * V_4 , int V_5 , int V_6 )
{
int V_7 , V_8 ;
while ( V_6 > 0 ) {
V_7 = F_2 ( V_3 , V_5 ) ;
V_6 -- ;
if ( V_6 <= 0 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 , - 1 ,
L_1 ) ;
return;
}
if ( V_7 > V_6 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 , - 1 ,
L_2 ,
V_7 , V_6 ) ;
return;
}
if ( V_1 ) {
T_5 * V_9 ;
F_4 ( V_3 , V_5 , V_7 + 1 ) ;
V_9 = F_5 ( V_1 , V_3 , V_5 , V_7 + 1 ,
L_3 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
F_6 ( V_9 , L_4 ,
F_2 ( V_3 , V_5 + V_8 + 1 ) ) ;
if ( ( ( V_8 & 1 ) == 0 ) &&
( V_8 + 1 < V_7 ) ) {
F_6 ( V_9 , L_5 ) ;
}
}
}
V_5 += V_7 + 1 ;
V_6 -= V_7 ;
}
}
void
F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 * V_10 , int V_5 , int V_6 )
{
T_6 V_11 ;
int V_12 ;
T_5 * V_9 ;
if ( V_6 <= 0 ) {
return;
}
V_11 = F_2 ( V_3 , V_5 ) ;
V_5 += 1 ;
V_6 -- ;
V_12 = FALSE ;
switch ( V_11 ) {
case 1 :
V_9 = F_5 ( V_1 , V_3 , V_5 - 1 , V_6 + 1 ,
L_6 , V_6 ) ;
if ( V_6 > 0 ) {
F_6 ( V_9 , L_7 ,
F_8 ( V_3 , V_5 , V_6 ) ) ;
} else {
F_6 ( V_9 , L_8 ) ;
}
break;
case 54 :
V_9 = F_5 ( V_1 , V_3 , V_5 - 1 , V_6 + 1 ,
L_9 , V_6 ) ;
if ( V_6 == 16 ) {
F_6 ( V_9 , L_10 , F_2 ( V_3 , V_5 ) ) ;
V_5 += 1 ;
V_6 -- ;
while ( V_6 > 0 ) {
F_6 ( V_9 , L_4 , F_2 ( V_3 , V_5 ) ) ;
V_5 += 1 ;
V_6 -- ;
}
} else {
F_6 ( V_9 ,
L_11 ) ;
}
break;
default:
F_5 ( V_1 , V_3 , V_5 - 1 , V_6 + 1 ,
L_12 , V_11 , V_6 ) ;
V_12 = TRUE ;
break;
}
if ( V_12 ) {
F_9 ( V_1 , V_2 , V_10 , V_3 , V_5 , - 1 ) ;
}
}
void
F_10 ( T_3 * V_3 , T_1 * V_1 , int V_5 ,
int V_6 )
{
if ( ! V_1 ) return;
if ( V_6 != 0 ) {
F_5 ( V_1 , V_3 , V_5 , V_6 ,
L_13 , V_6 ,
F_11 ( F_12 () , V_3 , V_5 , V_6 ) ) ;
}
}
void
F_13 ( T_3 * V_3 , T_1 * V_1 , int V_5 ,
int V_6 , int V_13 )
{
if ( ! V_1 ) return;
if ( V_6 == 0 ) {
F_5 ( V_1 , V_3 , V_5 , V_6 ,
L_14 ) ;
} else {
const char * V_14 = F_11 ( F_12 () , V_3 , V_5 , V_6 ) ;
F_14 ( V_1 , V_13 ,
V_3 , V_5 , V_6 ,
V_14 , L_15 , V_6 , V_14 ) ;
}
}
void
F_15 ( T_3 * V_3 , T_1 * V_1 , int V_5 , int V_6 ,
int V_13 )
{
T_7 V_15 ;
const char * V_16 ;
while ( V_6 > 0 ) {
if ( V_6 != 1 ) {
V_15 = F_16 ( V_3 , V_5 ) ;
switch( V_15 & 0x0fff ) {
case 0 :
V_16 = L_16 ;
break;
case 1 :
V_16 = L_17 ;
break;
case 2 :
V_16 = L_18 ;
break;
case 3 :
V_16 = L_19 ;
break;
case 4095 :
V_16 = L_20 ;
break;
default:
V_16 = L_21 ;
break;
}
F_17 ( V_1 , V_13 , V_3 , V_5 , 2 ,
V_15 ,
L_22 ,
V_16 ,
V_15 & 0xfff ,
( V_15 & 0x8000 ) ? L_23 : L_24 ,
( V_15 & 0x4000 ) ? L_25 : L_23 ) ;
} else {
F_5 ( V_1 , V_3 , V_5 , 1 ,
L_26 ) ;
break;
}
V_6 -= 2 ;
V_5 += 2 ;
}
}
void
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_5 , int V_6 , int V_13 )
{
if ( V_6 <= 0 ) {
return;
}
while ( V_6 > 0 ) {
if ( V_6 < 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 , - 1 ,
L_27 , V_6 ) ;
return;
}
if ( V_1 ) {
F_19 ( V_1 , V_13 , V_3 , V_5 , 4 , V_17 ) ;
}
V_5 += 4 ;
V_6 -= 4 ;
}
}
void
F_20 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_5 , int V_6 , int V_13 )
{
T_8 V_18 [ 16 ] ;
if ( V_6 <= 0 ) {
return;
}
while ( V_6 > 0 ) {
if ( V_6 < 16 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 , - 1 ,
L_28 , V_6 ) ;
return;
}
F_21 ( V_3 , V_18 , V_5 , sizeof( V_18 ) ) ;
if ( V_1 ) {
F_22 ( V_1 , V_13 , V_3 , V_5 , 16 , V_18 ) ;
}
V_5 += 16 ;
V_6 -= 16 ;
}
}
void
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
int V_5 , int V_6 , int V_13 )
{
if ( V_6 <= 0 ) {
return;
}
if ( V_6 != 4 ) {
F_3 ( V_1 , V_2 , V_4 , V_3 , V_5 , - 1 ,
L_29 , V_6 ) ;
return;
}
F_19 ( V_1 , V_13 , V_3 , V_5 , 4 , V_17 ) ;
}
void
F_24 ( T_3 * V_3 , T_1 * V_1 , int V_5 , int V_6 )
{
T_9 V_19 ;
T_5 * V_9 ;
if ( ! V_1 ) return;
F_4 ( V_3 , V_5 , V_6 ) ;
if ( V_6 <= 0 ) {
F_5 ( V_1 , V_3 , V_5 , V_6 ,
L_30 ) ;
} else {
V_19 = TRUE ;
V_9 = F_5 ( V_1 , V_3 , V_5 , V_6 ,
L_31 ) ;
while ( V_6 -- > 0 ) {
if ( ! V_19 ) {
F_6 ( V_9 , L_32 ) ;
}
F_6 ( V_9 , L_33 ,
( F_2 ( V_3 , V_5 ) == V_20
? L_34
: F_25 ( F_2 ( V_3 , V_5 ) , V_21 , L_35 ) ) ,
F_2 ( V_3 , V_5 ) ) ;
V_5 ++ ;
V_19 = FALSE ;
}
}
}
void
F_26 ( T_3 * V_3 , T_2 * V_2 , T_1 * V_1 , int V_5 ,
const T_10 * V_22 , T_4 * V_23 , int V_24 , int V_25 ,
int T_11 V_26 )
{
T_8 V_27 ;
T_8 V_6 ;
int V_28 ;
T_5 * V_9 ;
T_1 * V_29 ;
while ( V_24 > 0 ) {
V_27 = F_2 ( V_3 , V_5 ) ;
V_5 += 1 ;
V_24 -= 1 ;
if ( V_24 == 0 )
break;
V_6 = F_2 ( V_3 , V_5 ) ;
V_5 += 1 ;
V_24 -= 1 ;
if ( V_24 == 0 )
break;
if ( V_24 < V_6 ) {
F_3 ( V_1 , V_2 , V_23 , V_3 , V_5 , - 1 ,
L_36 ,
V_6 , V_24 ) ;
return;
}
V_28 = 0 ;
while ( ( V_22 [ V_28 ] . V_30 != NULL ) && ( V_22 [ V_28 ] . V_31 != V_27 ) ) {
V_28 ++ ;
}
if ( V_22 [ V_28 ] . V_30 ) {
if ( V_1 ) {
V_9 = F_5 ( V_1 , V_3 , V_5 - 2 ,
V_6 + 2 , L_37 ,
V_22 [ V_28 ] . V_32 , V_6 ) ;
V_29 = F_27 ( V_9 ,
* V_22 [ V_28 ] . V_13 ) ;
} else {
V_29 = NULL ;
}
V_22 [ V_28 ] . V_30 ( V_3 , V_2 , V_29 , V_5 ,
V_25 , V_6 ) ;
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
if ( V_1 ) {
F_5 ( V_1 , V_3 , V_5 - 2 ,
V_6 + 2 , L_38 ,
V_27 , V_6 ) ;
}
#endif
}
V_5 += V_6 ;
V_24 -= V_6 ;
}
}

void F_1 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
F_2 ( & V_1 -> V_3 ) ;
F_2 ( & V_1 -> V_4 ) ;
F_2 ( & V_1 -> V_5 ) ;
}
void F_3 ( T_1 * V_1 , unsigned short V_6 )
{
struct V_7 * V_8 ;
if ( V_1 -> V_9 != V_6 ) {
while ( F_4 ( & V_1 -> V_3 ) != NULL && V_1 -> V_9 != V_6 ) {
V_8 = F_5 ( & V_1 -> V_3 ) ;
F_6 ( V_8 ) ;
V_1 -> V_9 = ( V_1 -> V_9 + 1 ) % V_1 -> V_10 ;
}
}
}
void F_7 ( T_1 * V_1 )
{
struct V_7 * V_8 ;
while ( ( V_8 = F_8 ( & V_1 -> V_3 ) ) != NULL )
F_9 ( & V_1 -> V_2 , V_8 ) ;
}
int F_10 ( T_1 * V_1 , unsigned short V_6 )
{
unsigned short V_11 = V_1 -> V_9 ;
while ( V_11 != V_1 -> V_12 ) {
if ( V_6 == V_11 ) return 1 ;
V_11 = ( V_11 + 1 ) % V_1 -> V_10 ;
}
if ( V_6 == V_1 -> V_12 ) return 1 ;
return 0 ;
}
int F_11 ( T_1 * V_1 , struct V_7 * V_8 , int * V_13 , int * V_6 , int * V_14 )
{
unsigned char * V_15 ;
int V_16 = V_17 ;
V_15 = V_8 -> V_18 ;
* V_13 = * V_6 = * V_14 = 0 ;
if ( V_1 -> V_10 == V_19 ) {
if ( ( V_15 [ 0 ] & V_20 ) == 0 ) {
V_16 = V_21 ;
* V_13 = ( V_15 [ 0 ] >> 1 ) & 0x07 ;
* V_6 = ( V_15 [ 0 ] >> 5 ) & 0x07 ;
* V_14 = V_15 [ 0 ] & V_22 ;
} else if ( ( V_15 [ 0 ] & V_23 ) == 1 ) {
V_16 = V_15 [ 0 ] & 0x0F ;
* V_6 = ( V_15 [ 0 ] >> 5 ) & 0x07 ;
* V_14 = V_15 [ 0 ] & V_22 ;
} else if ( ( V_15 [ 0 ] & V_23 ) == 3 ) {
V_16 = V_15 [ 0 ] & ~ V_22 ;
* V_14 = V_15 [ 0 ] & V_22 ;
}
F_12 ( V_8 , 1 ) ;
} else {
if ( ( V_15 [ 0 ] & V_20 ) == 0 ) {
V_16 = V_21 ;
* V_13 = ( V_15 [ 0 ] >> 1 ) & 0x7F ;
* V_6 = ( V_15 [ 1 ] >> 1 ) & 0x7F ;
* V_14 = V_15 [ 1 ] & V_24 ;
F_12 ( V_8 , 2 ) ;
} else if ( ( V_15 [ 0 ] & V_23 ) == 1 ) {
V_16 = V_15 [ 0 ] & 0x0F ;
* V_6 = ( V_15 [ 1 ] >> 1 ) & 0x7F ;
* V_14 = V_15 [ 1 ] & V_24 ;
F_12 ( V_8 , 2 ) ;
} else if ( ( V_15 [ 0 ] & V_23 ) == 3 ) {
V_16 = V_15 [ 0 ] & ~ V_22 ;
* V_14 = V_15 [ 0 ] & V_22 ;
F_12 ( V_8 , 1 ) ;
}
}
return V_16 ;
}
void F_13 ( T_1 * V_1 , int V_16 , int V_25 , int type )
{
struct V_7 * V_8 ;
unsigned char * V_26 ;
if ( ( V_8 = F_14 ( V_1 -> V_27 -> V_28 -> V_29 + 2 , V_30 ) ) == NULL )
return;
F_15 ( V_8 , V_1 -> V_27 -> V_28 -> V_29 ) ;
F_16 ( V_8 ) ;
if ( V_1 -> V_10 == V_19 ) {
V_26 = F_17 ( V_8 , 1 ) ;
* V_26 = V_16 ;
* V_26 |= ( V_25 ) ? V_22 : 0 ;
if ( ( V_16 & V_23 ) == V_20 )
* V_26 |= ( V_1 -> V_31 << 5 ) ;
} else {
if ( ( V_16 & V_23 ) == V_23 ) {
V_26 = F_17 ( V_8 , 1 ) ;
* V_26 = V_16 ;
* V_26 |= ( V_25 ) ? V_22 : 0 ;
} else {
V_26 = F_17 ( V_8 , 2 ) ;
V_26 [ 0 ] = V_16 ;
V_26 [ 1 ] = ( V_1 -> V_31 << 1 ) ;
V_26 [ 1 ] |= ( V_25 ) ? V_24 : 0 ;
}
}
F_18 ( V_1 , V_8 , type ) ;
}
void F_19 ( struct V_32 * V_28 , T_2 * V_33 , T_2 * V_34 , T_3 * V_35 )
{
struct V_7 * V_8 ;
char * V_26 ;
T_3 V_36 ;
if ( V_28 == NULL )
return;
if ( ( V_8 = F_14 ( V_28 -> V_29 + 1 , V_30 ) ) == NULL )
return;
F_15 ( V_8 , V_28 -> V_29 ) ;
F_16 ( V_8 ) ;
F_20 ( V_35 , & V_36 ) ;
V_26 = F_17 ( V_8 , 1 ) ;
* V_26 = V_37 | V_22 ;
V_26 = F_21 ( V_8 , F_22 ( V_35 ) ) ;
V_26 += F_23 ( V_26 , V_34 , V_33 , & V_36 , V_38 , V_19 ) ;
F_24 ( V_8 , V_28 ) ;
}
void F_25 ( T_1 * V_1 )
{
int V_39 , V_40 = 2 ;
switch ( V_1 -> V_41 ) {
case 0 :
break;
case 1 :
V_40 += 2 * V_1 -> V_42 ;
break;
case 2 :
for ( V_39 = 0 ; V_39 < V_1 -> V_42 ; V_39 ++ )
V_40 *= 2 ;
if ( V_40 > 8 ) V_40 = 8 ;
break;
}
V_1 -> V_43 = V_40 * V_1 -> V_44 ;
}
void F_26 ( T_1 * V_1 )
{
if ( V_1 -> V_41 == 0 )
return;
if ( F_27 ( V_1 ) && V_1 -> V_42 == 0 )
V_1 -> V_44 = ( 9 * V_1 -> V_44 + V_1 -> V_43 - F_28 ( & V_1 -> V_45 ) ) / 10 ;
if ( V_1 -> V_44 < V_46 )
V_1 -> V_44 = V_46 ;
if ( V_1 -> V_44 > V_47 )
V_1 -> V_44 = V_47 ;
}
void F_29 ( T_1 * V_1 , int V_48 )
{
F_1 ( V_1 ) ;
if ( ! V_1 -> V_49 || ! F_30 ( V_1 -> V_49 , V_50 ) )
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
F_34 ( V_1 ) ;
F_35 ( V_1 ) ;
V_1 -> V_51 = V_52 ;
F_36 ( V_1 , V_48 ) ;
if ( V_1 -> V_49 != NULL ) {
F_37 () ;
F_38 ( V_1 -> V_49 ) ;
V_1 -> V_49 -> V_53 = V_54 ;
V_1 -> V_49 -> V_55 = V_48 ;
V_1 -> V_49 -> V_56 |= V_57 ;
if ( ! F_30 ( V_1 -> V_49 , V_58 ) ) {
V_1 -> V_49 -> V_59 ( V_1 -> V_49 ) ;
F_39 ( V_1 -> V_49 , V_58 ) ;
}
F_40 ( V_1 -> V_49 ) ;
F_41 () ;
}
}

static T_1 *
F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
T_2
F_2 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_1 ( V_2 ) ;
T_2 V_4 = ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ;
switch ( V_4 ) {
case 0x0200 :
case 0x0201 :
case 0x0300 :
return V_4 ;
default:
break;
}
F_3 ( V_2 , L_1 , V_3 [ 4 ] , V_3 [ 5 ] ) ;
return 0x0000 ;
}
T_2
F_4 ( struct V_1 * V_2 )
{
return 8 ;
}
T_2
F_5 ( struct V_1 * V_2 )
{
return * ( T_2 * ) & F_1 ( V_2 ) [ 6 ] ;
}
bool
F_6 ( struct V_1 * V_2 )
{
T_2 V_5 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
T_1 * V_3 = F_1 ( V_2 ) , V_6 = 0 ;
while ( V_5 -- )
V_6 += * V_3 ++ ;
if ( V_6 ) {
F_3 ( V_2 , L_2 ) ;
return false ;
}
return true ;
}
bool
F_7 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_1 ( V_2 ) ;
if ( * ( V_7 * ) V_3 != 0x5f4d584d ) {
F_3 ( V_2 , L_3 ) ;
return false ;
}
if ( ! F_2 ( V_2 ) || ! F_6 ( V_2 ) )
return false ;
return true ;
}
bool
F_8 ( struct V_1 * V_2 , T_1 V_8 ,
bool (* F_9)( struct V_1 * , T_1 * , void * ) , void * V_9 )
{
T_1 * V_3 = F_1 ( V_2 ) ;
T_1 * V_10 = V_3 + F_4 ( V_2 ) ;
T_1 * V_11 = V_10 + F_5 ( V_2 ) - 1 ;
while ( V_10 < V_11 ) {
T_1 type = V_10 [ 0 ] & 0x0f ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 = 0 ;
switch ( type ) {
case 0 :
if ( F_2 ( V_2 ) >= 0x0300 )
V_12 = 8 ;
else
V_12 = 6 ;
break;
case 1 :
case 2 :
case 3 :
V_12 = 4 ;
break;
case 4 :
V_12 = 4 ;
V_13 = 2 ;
V_14 = ( F_10 ( V_10 [ 0 ] ) & 0x01f00000 ) >> 20 ;
break;
case 5 :
V_12 = 8 ;
break;
case 6 :
if ( F_2 ( V_2 ) >= 0x0300 ) {
V_12 = 4 ;
V_13 = 8 ;
V_14 = ( V_10 [ 1 ] & 0xf0 ) >> 4 ;
} else {
V_12 = 8 ;
}
break;
case 7 :
V_12 = 8 ;
V_13 = 4 ;
V_14 = V_10 [ 1 ] & 0x07 ;
break;
default:
F_3 ( V_2 , L_4 , type ) ;
return false ;
}
if ( F_11 ( V_2 ) -> V_15 >= V_16 && ( F_9 == NULL ) ) {
static const char * V_17 [] = {
L_5 , L_6 , L_7 , L_8 ,
L_9 , L_10 , L_11 , L_12 ,
} ;
T_1 * V_18 = V_10 ;
int V_19 , V_20 ;
F_3 ( V_2 , L_13 , V_17 [ type ] ) ;
for ( V_20 = V_12 - 1 ; V_20 >= 0 ; V_20 -- )
F_12 ( L_14 , V_18 [ V_20 ] ) ;
F_12 ( L_15 ) ;
V_18 += V_12 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ , V_18 += V_13 ) {
F_3 ( V_2 , L_16 ) ;
for ( V_20 = V_13 - 1 ; V_20 >= 0 ; V_20 -- )
F_12 ( L_14 , V_18 [ V_20 ] ) ;
F_12 ( L_15 ) ;
}
}
if ( V_8 & ( 1 << type ) ) {
if ( ! F_9 ( V_2 , V_10 , V_9 ) )
return false ;
}
V_10 += V_12 + ( V_14 * V_13 ) ;
}
return true ;
}
void
F_13 ( struct V_1 * V_2 , T_1 * V_21 , struct V_22 * V_10 )
{
T_3 V_23 = F_10 ( V_21 [ 0 ] ) ;
if ( F_2 ( V_2 ) >= 0x0300 )
V_23 |= ( T_3 ) F_14 ( V_21 [ 4 ] ) << 32 ;
V_10 -> V_24 = ( V_23 & 0x00000000000000f0ULL ) >> 4 ;
V_10 -> V_25 = ( V_23 & 0x0000000000000f00ULL ) >> 8 ;
V_10 -> V_26 = ( V_23 & 0x000000000001f000ULL ) >> 12 ;
V_10 -> V_27 = ( V_23 & 0x0000000000780000ULL ) >> 19 ;
}

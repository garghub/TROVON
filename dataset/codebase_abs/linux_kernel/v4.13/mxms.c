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
F_3 ( & V_2 -> V_5 , L_1 , V_3 [ 4 ] , V_3 [ 5 ] ) ;
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
T_2 V_6 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
T_1 * V_3 = F_1 ( V_2 ) , V_7 = 0 ;
while ( V_6 -- )
V_7 += * V_3 ++ ;
if ( V_7 ) {
F_3 ( & V_2 -> V_5 , L_2 ) ;
return false ;
}
return true ;
}
bool
F_7 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_1 ( V_2 ) ;
if ( * ( V_8 * ) V_3 != 0x5f4d584d ) {
F_3 ( & V_2 -> V_5 , L_3 ) ;
return false ;
}
if ( ! F_2 ( V_2 ) || ! F_6 ( V_2 ) )
return false ;
return true ;
}
bool
F_8 ( struct V_1 * V_2 , T_1 V_9 ,
bool (* F_9)( struct V_1 * , T_1 * , void * ) , void * V_10 )
{
struct V_11 * V_5 = & V_2 -> V_5 ;
T_1 * V_3 = F_1 ( V_2 ) ;
T_1 * V_12 = V_3 + F_4 ( V_2 ) ;
T_1 * V_13 = V_12 + F_5 ( V_2 ) - 1 ;
while ( V_12 < V_13 ) {
T_1 type = V_12 [ 0 ] & 0x0f ;
T_1 V_14 = 0 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
switch ( type ) {
case 0 :
if ( F_2 ( V_2 ) >= 0x0300 )
V_14 = 8 ;
else
V_14 = 6 ;
break;
case 1 :
case 2 :
case 3 :
V_14 = 4 ;
break;
case 4 :
V_14 = 4 ;
V_15 = 2 ;
V_16 = ( F_10 ( V_12 [ 0 ] ) & 0x01f00000 ) >> 20 ;
break;
case 5 :
V_14 = 8 ;
break;
case 6 :
if ( F_2 ( V_2 ) >= 0x0300 ) {
V_14 = 4 ;
V_15 = 8 ;
V_16 = ( V_12 [ 1 ] & 0xf0 ) >> 4 ;
} else {
V_14 = 8 ;
}
break;
case 7 :
V_14 = 8 ;
V_15 = 4 ;
V_16 = V_12 [ 1 ] & 0x07 ;
break;
default:
F_3 ( V_5 , L_4 , type ) ;
return false ;
}
if ( V_2 -> V_5 . V_17 >= V_18 && ( F_9 == NULL ) ) {
static const char * V_19 [] = {
L_5 , L_6 , L_7 , L_8 ,
L_9 , L_10 , L_11 , L_12 ,
} ;
T_1 * V_20 = V_12 ;
char V_21 [ 32 ] , * V_22 ;
int V_23 , V_24 ;
for ( V_24 = V_14 - 1 , V_22 = V_21 ; V_24 >= 0 ; V_24 -- )
V_22 += sprintf ( V_22 , L_13 , V_20 [ V_24 ] ) ;
V_20 += V_14 ;
F_3 ( V_5 , L_14 , V_19 [ type ] , V_21 ) ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ , V_20 += V_15 ) {
for ( V_24 = V_15 - 1 , V_22 = V_21 ; V_24 >= 0 ; V_24 -- )
V_22 += sprintf ( V_22 , L_13 , V_20 [ V_24 ] ) ;
F_3 ( V_5 , L_15 , V_21 ) ;
}
}
if ( V_9 & ( 1 << type ) ) {
if ( ! F_9 ( V_2 , V_12 , V_10 ) )
return false ;
}
V_12 += V_14 + ( V_16 * V_15 ) ;
}
return true ;
}
void
F_11 ( struct V_1 * V_2 , T_1 * V_25 , struct V_26 * V_12 )
{
T_3 V_21 = F_10 ( V_25 [ 0 ] ) ;
if ( F_2 ( V_2 ) >= 0x0300 )
V_21 |= ( T_3 ) F_12 ( V_25 [ 4 ] ) << 32 ;
V_12 -> V_27 = ( V_21 & 0x00000000000000f0ULL ) >> 4 ;
V_12 -> V_28 = ( V_21 & 0x0000000000000f00ULL ) >> 8 ;
V_12 -> V_29 = ( V_21 & 0x000000000001f000ULL ) >> 12 ;
V_12 -> V_30 = ( V_21 & 0x0000000000780000ULL ) >> 19 ;
}

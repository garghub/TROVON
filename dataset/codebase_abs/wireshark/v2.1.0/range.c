T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( V_2 ) ;
V_1 -> V_3 = 0 ;
return V_1 ;
}
T_2
F_3 ( T_1 * * V_4 , const T_3 * V_5 , T_4 V_6 )
{
return F_4 ( V_4 , V_5 , V_6 , TRUE ) ;
}
T_2
F_4 ( T_1 * * V_4 , const T_3 * V_5 , T_4 V_6 ,
T_5 V_7 )
{
T_1 * V_1 ;
T_6 V_3 ;
const T_3 * V_8 ;
char * V_9 ;
T_3 V_10 ;
T_6 V_11 ;
T_4 V_12 ;
unsigned long V_13 ;
if ( ( V_4 == NULL ) || ( V_5 == NULL ) )
return V_14 ;
V_1 = ( T_1 * ) F_2 ( V_2 + sizeof ( V_15 ) ) ;
V_1 -> V_3 = 0 ;
V_3 = 1 ;
V_8 = V_5 ;
for (; ; ) {
while ( ( V_10 = * V_8 ) == ' ' || V_10 == '\t' )
V_8 ++ ;
if ( V_10 == '\0' )
break;
if ( V_1 -> V_3 >= V_3 ) {
if ( V_3 == 1 )
V_3 = 4 ;
else
V_3 += 4 ;
V_1 = ( T_1 * ) F_5 ( V_1 , V_2 +
V_3 * sizeof ( V_15 ) ) ;
}
if ( V_10 == '-' ) {
V_1 -> V_16 [ V_1 -> V_3 ] . V_17 = 1 ;
} else if ( F_6 ( V_10 ) ) {
V_18 = 0 ;
V_13 = strtoul ( V_8 , & V_9 , 0 ) ;
if ( V_8 == V_9 ) {
F_7 ( V_1 ) ;
return V_14 ;
}
if ( V_18 == V_19 || V_13 > V_6 ) {
if ( V_7 ) {
F_7 ( V_1 ) ;
return V_20 ;
} else {
V_13 = V_6 ;
}
}
V_8 = V_9 ;
V_1 -> V_16 [ V_1 -> V_3 ] . V_17 = ( T_4 ) V_13 ;
while ( ( V_10 = * V_8 ) == ' ' || V_10 == '\t' )
V_8 ++ ;
} else {
F_7 ( V_1 ) ;
return V_14 ;
}
if ( V_10 == '-' ) {
V_8 ++ ;
while ( ( V_10 = * V_8 ) == ' ' || V_10 == '\t' )
V_8 ++ ;
if ( V_10 == ',' || V_10 == '\0' ) {
V_1 -> V_16 [ V_1 -> V_3 ] . V_21 = V_6 ;
} else if ( F_6 ( V_10 ) ) {
V_18 = 0 ;
V_13 = strtoul ( V_8 , & V_9 , 0 ) ;
if ( V_8 == V_9 ) {
F_7 ( V_1 ) ;
return V_14 ;
}
if ( V_18 == V_19 || V_13 > V_6 ) {
if ( V_7 ) {
F_7 ( V_1 ) ;
return V_20 ;
} else {
V_13 = V_6 ;
}
}
V_8 = V_9 ;
V_1 -> V_16 [ V_1 -> V_3 ] . V_21 = ( T_4 ) V_13 ;
while ( ( V_10 = * V_8 ) == ' ' || V_10 == '\t' )
V_8 ++ ;
} else {
F_7 ( V_1 ) ;
return V_14 ;
}
} else if ( V_10 == ',' || V_10 == '\0' ) {
V_1 -> V_16 [ V_1 -> V_3 ] . V_21 = V_1 -> V_16 [ V_1 -> V_3 ] . V_17 ;
} else {
F_7 ( V_1 ) ;
return V_14 ;
}
V_1 -> V_3 ++ ;
if ( V_10 == ',' ) {
V_8 ++ ;
}
}
for ( V_11 = 0 ; V_11 < V_1 -> V_3 ; V_11 ++ ) {
if ( V_1 -> V_16 [ V_11 ] . V_17 > V_1 -> V_16 [ V_11 ] . V_21 ) {
V_12 = V_1 -> V_16 [ V_11 ] . V_17 ;
V_1 -> V_16 [ V_11 ] . V_17 = V_1 -> V_16 [ V_11 ] . V_21 ;
V_1 -> V_16 [ V_11 ] . V_21 = V_12 ;
}
}
* V_4 = V_1 ;
return V_22 ;
}
T_5
F_8 ( T_1 * V_1 , T_4 V_13 )
{
T_6 V_11 ;
if ( V_1 ) {
for ( V_11 = 0 ; V_11 < V_1 -> V_3 ; V_11 ++ ) {
if ( V_13 >= V_1 -> V_16 [ V_11 ] . V_17 && V_13 <= V_1 -> V_16 [ V_11 ] . V_21 )
return TRUE ;
}
}
return ( FALSE ) ;
}
T_5
F_9 ( T_1 * V_23 , T_1 * V_24 )
{
T_6 V_11 ;
if ( ( V_23 == NULL ) || ( V_24 == NULL ) )
return FALSE ;
if ( V_23 -> V_3 != V_24 -> V_3 )
return FALSE ;
for ( V_11 = 0 ; V_11 < V_23 -> V_3 ; V_11 ++ ) {
if ( V_23 -> V_16 [ V_11 ] . V_17 != V_24 -> V_16 [ V_11 ] . V_17 )
return FALSE ;
if ( V_23 -> V_16 [ V_11 ] . V_21 != V_24 -> V_16 [ V_11 ] . V_21 )
return FALSE ;
}
return TRUE ;
}
void
F_10 ( T_1 * V_1 , void (* F_11)( T_4 V_13 ) )
{
T_4 V_11 , V_25 ;
if ( V_1 && F_11 ) {
for ( V_11 = 0 ; V_11 < V_1 -> V_3 ; V_11 ++ ) {
for ( V_25 = V_1 -> V_16 [ V_11 ] . V_17 ; V_25 <= V_1 -> V_16 [ V_11 ] . V_21 ; V_25 ++ )
F_11 ( V_25 ) ;
}
}
}
char *
F_12 ( T_7 * V_26 , const T_1 * V_1 )
{
T_4 V_11 ;
T_5 V_27 = FALSE ;
T_8 * V_28 ;
V_28 = F_13 ( V_26 , L_1 ) ;
if ( V_1 ) {
for ( V_11 = 0 ; V_11 < V_1 -> V_3 ; V_11 ++ ) {
if ( V_1 -> V_16 [ V_11 ] . V_17 == V_1 -> V_16 [ V_11 ] . V_21 ) {
F_14 ( V_28 , L_2 , V_27 ? L_3 : L_1 , V_1 -> V_16 [ V_11 ] . V_17 ) ;
} else {
F_14 ( V_28 , L_4 , V_27 ? L_3 : L_1 , V_1 -> V_16 [ V_11 ] . V_17 , V_1 -> V_16 [ V_11 ] . V_21 ) ;
}
V_27 = TRUE ;
}
}
return F_15 ( V_28 ) ;
}
T_1 *
F_16 ( T_1 * V_29 )
{
T_1 * V_30 ;
T_9 V_31 ;
if ( V_29 == NULL )
return NULL ;
V_31 = V_2 + V_29 -> V_3 * sizeof ( V_15 ) ;
V_30 = ( T_1 * ) F_2 ( V_31 ) ;
memcpy ( V_30 , V_29 , V_31 ) ;
return V_30 ;
}

char * F_1 ( int V_1 )
{
if ( V_1 == V_2 ) {
if ( ! V_3 ) {
V_3 = true ;
F_2 ( V_4 , sizeof( V_4 ) ,
V_5 [ V_1 ] . V_6 ,
V_7 ) ;
}
return V_4 ;
}
return ( char * ) V_5 [ V_1 ] . V_6 ;
}
int F_3 ( const char * V_8 )
{
char * V_9 , * V_10 = NULL ;
bool V_11 = false ;
char * V_12 ;
int V_13 ;
V_12 = malloc ( strlen ( V_8 ) + 1 ) ;
if ( ! V_12 )
return - V_14 ;
strcpy ( V_12 , V_8 ) ;
V_9 = strtok_r ( ( char * ) V_12 , L_1 , & V_10 ) ;
while ( V_9 ) {
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
struct V_16 * V_17 = & V_5 [ V_13 ] ;
if ( strstr ( V_17 -> V_18 , V_9 ) )
V_17 -> V_19 = V_11 = true ;
}
V_9 = strtok_r ( NULL , L_1 , & V_10 ) ;
}
free ( V_12 ) ;
if ( V_11 )
return 0 ;
F_4 ( L_2 , V_8 ) ;
return - 1 ;
}
int F_5 ( void )
{
const char * V_20 = F_6 () ;
bool V_11 = false ;
int V_13 ;
if ( ! V_20 )
return - V_21 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
char V_22 [ V_23 ] ;
struct V_16 * V_17 = & V_5 [ V_13 ] ;
struct V_24 V_25 ;
F_2 ( V_22 , V_23 , L_3 ,
V_20 , V_17 -> V_26 ) ;
if ( ! V_24 ( V_22 , & V_25 ) )
V_17 -> V_27 = V_11 = true ;
}
return V_11 ? 0 : - V_21 ;
}
int F_7 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_31 = 0 , V_1 ;
T_2 V_32 = V_33 ;
T_2 V_34 , V_35 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_37 ;
V_34 = V_32 & V_38 ;
V_35 = V_32 & V_39 ;
V_32 &= ~ ( V_38 | V_39 ) ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_40 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_40 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
if ( V_34 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_6 ) ;
if ( V_35 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_7 ) ;
return V_31 ;
}
int F_9 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_1 , V_31 = 0 ;
T_2 V_32 = V_41 ;
T_2 V_34 , V_35 ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_42 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
V_34 = V_32 & V_43 ;
V_35 = V_32 & V_44 ;
V_32 &= ~ ( V_43 | V_44 ) ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_42 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_42 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
if ( V_34 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_6 ) ;
if ( V_35 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_7 ) ;
return V_31 ;
}
int F_10 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_1 , V_31 = 0 ;
T_2 V_32 = V_45 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_46 ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_47 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_47 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
return V_31 ;
}
int F_11 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_2 V_48 = V_49 ;
int V_31 ;
if ( V_30 )
V_48 = V_30 -> V_36 . V_50 ;
if ( V_48 & V_49 )
V_31 = F_2 ( V_28 , V_29 , L_5 ) ;
else if ( V_48 & V_51 )
V_31 = F_2 ( V_28 , V_29 , L_8 ) ;
else
V_31 = F_2 ( V_28 , V_29 , L_9 ) ;
return V_31 ;
}
int F_12 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
int V_1 = 0 ;
V_1 += F_9 ( V_28 , V_29 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_10 ) ;
V_1 += F_10 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_11 ) ;
V_1 += F_7 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_12 ) ;
V_1 += F_11 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
return V_1 ;
}

char * F_1 ( int V_1 )
{
return ( char * ) V_2 [ V_1 ] . V_3 ;
}
int F_2 ( const char * V_4 )
{
char * V_5 , * V_6 = NULL ;
bool V_7 = false ;
char * V_8 ;
int V_9 ;
V_8 = malloc ( strlen ( V_4 ) + 1 ) ;
if ( ! V_8 )
return - V_10 ;
strcpy ( V_8 , V_4 ) ;
V_5 = strtok_r ( ( char * ) V_8 , L_1 , & V_6 ) ;
while ( V_5 ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_12 * V_13 = & V_2 [ V_9 ] ;
if ( strstr ( V_13 -> V_14 , V_5 ) )
V_13 -> V_15 = V_7 = true ;
}
V_5 = strtok_r ( NULL , L_1 , & V_6 ) ;
}
free ( V_8 ) ;
if ( V_7 )
return 0 ;
F_3 ( L_2 , V_4 ) ;
return - 1 ;
}
int F_4 ( void )
{
const char * V_16 = F_5 () ;
bool V_7 = false ;
int V_9 ;
if ( ! V_16 )
return - V_17 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
char V_18 [ V_19 ] ;
struct V_12 * V_13 = & V_2 [ V_9 ] ;
struct V_20 V_21 ;
F_6 ( V_18 , V_19 , L_3 ,
V_16 , V_13 -> V_22 ) ;
if ( ! V_20 ( V_18 , & V_21 ) )
V_13 -> V_23 = V_7 = true ;
}
return V_7 ? 0 : - V_17 ;
}
int F_7 ( char * V_24 , T_1 V_25 , struct V_26 * V_26 )
{
T_1 V_27 = 0 , V_1 ;
T_2 V_28 = V_29 ;
T_2 V_30 , V_31 ;
V_25 -= 1 ;
V_24 [ 0 ] = '\0' ;
if ( V_26 )
V_28 = V_26 -> V_32 . V_33 ;
V_30 = V_28 & V_34 ;
V_31 = V_28 & V_35 ;
V_28 &= ~ ( V_34 | V_35 ) ;
for ( V_1 = 0 ; V_28 && V_1 < F_8 ( V_36 ) ; V_1 ++ , V_28 >>= 1 ) {
if ( ! ( V_28 & 0x1 ) )
continue;
if ( V_27 ) {
strcat ( V_24 , L_4 ) ;
V_27 += 4 ;
}
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , V_36 [ V_1 ] ) ;
}
if ( * V_24 == '\0' )
V_27 += F_6 ( V_24 , V_25 - V_27 , L_5 ) ;
if ( V_30 )
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , L_6 ) ;
if ( V_31 )
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , L_7 ) ;
return V_27 ;
}
int F_9 ( char * V_24 , T_1 V_25 , struct V_26 * V_26 )
{
T_1 V_1 , V_27 = 0 ;
T_2 V_28 = V_37 ;
T_2 V_30 , V_31 ;
if ( V_26 )
V_28 = V_26 -> V_32 . V_38 ;
V_25 -= 1 ;
V_24 [ 0 ] = '\0' ;
V_30 = V_28 & V_39 ;
V_31 = V_28 & V_40 ;
V_28 &= ~ ( V_39 | V_40 ) ;
for ( V_1 = 0 ; V_28 && V_1 < F_8 ( V_38 ) ; V_1 ++ , V_28 >>= 1 ) {
if ( ! ( V_28 & 0x1 ) )
continue;
if ( V_27 ) {
strcat ( V_24 , L_4 ) ;
V_27 += 4 ;
}
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , V_38 [ V_1 ] ) ;
}
if ( * V_24 == '\0' )
V_27 += F_6 ( V_24 , V_25 - V_27 , L_5 ) ;
if ( V_30 )
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , L_6 ) ;
if ( V_31 )
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , L_7 ) ;
return V_27 ;
}
int F_10 ( char * V_24 , T_1 V_25 , struct V_26 * V_26 )
{
T_1 V_1 , V_27 = 0 ;
T_2 V_28 = V_41 ;
V_25 -= 1 ;
V_24 [ 0 ] = '\0' ;
if ( V_26 )
V_28 = V_26 -> V_32 . V_42 ;
for ( V_1 = 0 ; V_28 && V_1 < F_8 ( V_43 ) ; V_1 ++ , V_28 >>= 1 ) {
if ( ! ( V_28 & 0x1 ) )
continue;
if ( V_27 ) {
strcat ( V_24 , L_4 ) ;
V_27 += 4 ;
}
V_27 += F_6 ( V_24 + V_27 , V_25 - V_27 , V_43 [ V_1 ] ) ;
}
if ( * V_24 == '\0' )
V_27 += F_6 ( V_24 , V_25 - V_27 , L_5 ) ;
return V_27 ;
}
int F_11 ( char * V_24 , T_1 V_25 , struct V_26 * V_26 )
{
T_2 V_44 = V_45 ;
int V_27 ;
if ( V_26 )
V_44 = V_26 -> V_32 . V_46 ;
if ( V_44 & V_45 )
V_27 = F_6 ( V_24 , V_25 , L_5 ) ;
else if ( V_44 & V_47 )
V_27 = F_6 ( V_24 , V_25 , L_8 ) ;
else
V_27 = F_6 ( V_24 , V_25 , L_9 ) ;
return V_27 ;
}
int F_12 ( char * V_24 , T_1 V_25 , struct V_26 * V_26 )
{
int V_1 = 0 ;
V_1 += F_9 ( V_24 , V_25 , V_26 ) ;
V_1 += F_6 ( V_24 + V_1 , V_25 - V_1 , L_10 ) ;
V_1 += F_10 ( V_24 + V_1 , V_25 - V_1 , V_26 ) ;
V_1 += F_6 ( V_24 + V_1 , V_25 - V_1 , L_11 ) ;
V_1 += F_7 ( V_24 + V_1 , V_25 - V_1 , V_26 ) ;
V_1 += F_6 ( V_24 + V_1 , V_25 - V_1 , L_12 ) ;
V_1 += F_11 ( V_24 + V_1 , V_25 - V_1 , V_26 ) ;
return V_1 ;
}

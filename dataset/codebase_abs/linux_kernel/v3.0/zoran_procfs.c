static void
F_1 ( struct V_1 * V_2 ,
char * V_3 ,
char * V_4 )
{
int V_5 = 0 , V_6 , V_7 , V_8 ;
while ( V_9 [ V_5 ] . V_3 != NULL ) {
if ( ! strncmp ( V_3 , V_9 [ V_5 ] . V_3 , strlen ( V_9 [ V_5 ] . V_3 ) ) ) {
V_7 = V_6 = F_2 ( V_9 [ V_5 ] . V_7 ) ;
V_7 &= ~ ( V_9 [ V_5 ] . V_10 << V_9 [ V_5 ] . V_11 ) ;
if ( ! isdigit ( V_4 [ 0 ] ) )
break;
V_8 = F_3 ( V_4 , NULL , 0 ) ;
if ( ( V_8 & ~ V_9 [ V_5 ] . V_10 ) )
break;
V_7 |= ( V_8 & V_9 [ V_5 ] . V_10 ) << V_9 [ V_5 ] . V_11 ;
F_4 ( 4 ,
V_12
L_1 ,
F_5 ( V_2 ) , V_9 [ V_5 ] . V_7 , V_6 , V_7 ,
V_9 [ V_5 ] . V_3 , V_8 ) ;
F_6 ( V_7 , V_9 [ V_5 ] . V_7 ) ;
break;
}
V_5 ++ ;
}
}
static int F_7 ( struct V_13 * V_14 , void * V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
int V_5 ;
F_8 ( V_14 , L_2 ) ;
for ( V_5 = 0 ; V_5 < 0x130 ; V_5 += 16 )
F_8 ( V_14 , L_3 , V_5 ,
F_2 ( V_5 ) , F_2 ( V_5 + 4 ) , F_2 ( V_5 + 8 ) , F_2 ( V_5 + 12 ) ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
struct V_1 * V_19 = F_10 ( V_17 ) -> V_19 ;
return F_11 ( V_18 , F_7 , V_19 ) ;
}
static T_1 F_12 ( struct V_18 * V_18 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_1 * V_2 = F_10 ( V_18 -> V_23 . V_24 -> V_25 ) -> V_19 ;
char * string , * V_26 ;
char * line , * V_27 , * V_28 , * V_29 , * V_30 ;
if ( V_21 > 32768 )
return - V_31 ;
string = V_26 = F_13 ( V_21 + 1 ) ;
if ( ! string ) {
F_4 ( 1 ,
V_32
L_4 ,
F_5 ( V_2 ) ) ;
return - V_33 ;
}
if ( F_14 ( string , V_20 , V_21 ) ) {
F_15 ( string ) ;
return - V_34 ;
}
string [ V_21 ] = 0 ;
F_4 ( 4 , V_12 L_5 ,
F_5 ( V_2 ) , V_18 -> V_23 . V_24 -> V_35 . V_3 , V_21 , V_2 ) ;
V_27 = L_6 ;
V_30 = L_7 ;
line = strpbrk ( V_26 , V_27 ) ;
while ( line ) {
* line = 0 ;
V_29 = strpbrk ( V_26 , V_30 ) ;
if ( V_29 ) {
* V_29 = 0 ;
V_28 = V_26 ;
V_29 ++ ;
F_1 ( V_2 , V_28 , V_29 ) ;
}
V_26 = line + 1 ;
line = strpbrk ( V_26 , V_27 ) ;
}
F_15 ( string ) ;
return V_21 ;
}
int
F_16 ( struct V_1 * V_2 )
{
#ifdef F_17
char V_3 [ 8 ] ;
snprintf ( V_3 , 7 , L_8 , V_2 -> V_36 ) ;
V_2 -> V_37 = F_18 ( V_3 , 0 , NULL , & V_38 , V_2 ) ;
if ( V_2 -> V_37 != NULL ) {
F_4 ( 2 ,
V_12
L_9 ,
F_5 ( V_2 ) , V_3 , V_2 -> V_37 -> V_19 ) ;
} else {
F_4 ( 1 , V_32 L_10 ,
F_5 ( V_2 ) , V_3 ) ;
return 1 ;
}
#endif
return 0 ;
}
void
F_19 ( struct V_1 * V_2 )
{
#ifdef F_17
char V_3 [ 8 ] ;
snprintf ( V_3 , 7 , L_8 , V_2 -> V_36 ) ;
if ( V_2 -> V_37 )
F_20 ( V_3 , NULL ) ;
V_2 -> V_37 = NULL ;
#endif
}

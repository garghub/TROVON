bool F_1 ( T_1 V_1 )
{
return V_1 . V_2 == V_3 ||
V_1 . V_2 == V_4 ||
V_1 . V_2 == V_5 ;
}
int F_2 ( struct V_6 * V_7 ,
struct V_6 * T_2 V_8 )
{
char * V_9 = V_7 -> V_10 ;
if ( * V_9 == '.' )
V_9 ++ ;
if ( strlen ( V_9 ) >= 3 && ! strncmp ( V_9 , L_1 , 3 ) )
return V_11 ;
if ( strlen ( V_9 ) >= 10 && ! strncmp ( V_9 , L_2 , 10 ) )
return V_11 ;
return V_12 ;
}
int F_3 ( const char * V_13 , const char * V_14 )
{
if ( * V_13 == '.' )
V_13 ++ ;
if ( * V_14 == '.' )
V_14 ++ ;
return strcmp ( V_13 , V_14 ) ;
}
int F_4 ( const char * V_13 , const char * V_14 ,
unsigned int V_15 )
{
if ( * V_13 == '.' )
V_13 ++ ;
if ( * V_14 == '.' )
V_14 ++ ;
return strncmp ( V_13 , V_14 , V_15 ) ;
}
void F_5 ( struct V_6 * V_16 , T_3 * V_9 )
{
V_16 -> V_17 = V_9 -> V_18 ;
}
void F_6 ( struct V_19 * V_20 ,
struct V_21 * V_22 , struct V_23 * V_23 ,
struct V_6 * V_9 )
{
int V_24 ;
if ( V_20 -> V_25 . V_26 || ! V_23 || ! V_9 )
return;
if ( ! V_20 -> V_27 && V_20 -> V_25 . V_28 ) {
#ifdef F_7
if ( ! F_8 () )
#endif
return;
}
V_24 = F_9 ( V_9 -> V_17 ) ;
if ( V_23 -> V_29 -> V_30 == V_31 )
V_22 -> V_25 . V_26 += V_32 ;
else if ( V_24 ) {
if ( V_20 -> V_27 )
V_22 -> V_25 . V_33 += V_24 ;
else
V_22 -> V_25 . V_26 += V_24 ;
}
}
void F_10 ( struct V_19 * V_20 ,
int V_34 )
{
struct V_21 * V_22 ;
struct V_23 * V_23 ;
struct V_6 * V_9 = NULL ;
struct V_35 * V_36 ;
int V_37 = 0 ;
V_23 = F_11 ( V_20 -> V_38 , V_20 -> V_27 ) ;
if ( ! V_23 || F_12 ( V_23 ) < 0 )
return;
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
V_22 = & V_20 -> V_39 [ V_37 ] ;
F_13 (map, sym, tmp) {
if ( V_23 -> V_40 ( V_23 , V_9 -> V_41 ) == V_22 -> V_25 . V_33 )
F_6 ( V_20 , V_22 , V_23 , V_9 ) ;
}
}
}

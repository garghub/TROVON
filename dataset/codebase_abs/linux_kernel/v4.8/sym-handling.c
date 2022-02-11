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
void F_4 ( struct V_6 * V_15 , T_3 * V_9 )
{
V_15 -> V_16 = V_9 -> V_17 ;
}
void F_5 ( struct V_18 * V_19 ,
struct V_20 * V_21 , struct V_22 * V_22 ,
struct V_6 * V_9 )
{
int V_23 ;
if ( V_19 -> V_24 . V_25 || V_19 -> V_24 . V_26 || ! V_22 || ! V_9 )
return;
V_23 = F_6 ( V_9 -> V_16 ) ;
if ( V_22 -> V_27 -> V_28 == V_29 )
V_21 -> V_24 . V_25 += V_30 ;
else if ( V_23 ) {
if ( V_19 -> V_31 )
V_21 -> V_24 . V_32 += V_23 ;
else
V_21 -> V_24 . V_25 += V_23 ;
}
}
void F_7 ( struct V_18 * V_19 ,
int V_33 )
{
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_6 * V_9 = NULL ;
struct V_34 * V_35 ;
int V_36 = 0 ;
V_22 = F_8 ( V_19 -> V_37 , V_19 -> V_31 ) ;
if ( ! V_22 || F_9 ( V_22 , NULL ) < 0 )
return;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
V_21 = & V_19 -> V_38 [ V_36 ] ;
F_10 (map, sym, tmp) {
if ( V_22 -> V_39 ( V_22 , V_9 -> V_40 ) == V_21 -> V_24 . V_32 )
F_5 ( V_19 , V_21 , V_22 , V_9 ) ;
}
}
}

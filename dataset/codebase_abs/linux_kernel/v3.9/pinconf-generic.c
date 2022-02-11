void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_4 ( V_2 , V_5 , & V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 &&
F_7 ( V_13 ) != 0 )
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ,
V_12 [ V_10 ] . V_19 ) ;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_20 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_9 ( F_10 ( V_2 -> V_21 ) , V_20 ,
& V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 && V_13 != 0 )
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ,
V_12 [ V_10 ] . V_19 ) ;
}
}

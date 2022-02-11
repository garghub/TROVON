int F_1 ( struct V_1 * V_2 , int V_3 , int type )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
unsigned int V_10 ;
int V_11 ;
V_5 = F_2 ( V_2 -> V_12 ) ;
if ( ! V_5 )
return - V_13 ;
V_7 = F_3 ( & V_2 -> V_14 , struct V_6 , V_15 ) ;
if ( V_7 -> V_16 . V_17 ) {
V_9 . V_18 = 0 ;
V_9 . V_19 = V_20 >> 32 ;
} else {
V_9 . V_18 = V_21 ;
V_9 . V_19 = 0 ;
}
F_4 (entry, &dev->msi_list, list) {
V_11 = F_5 ( V_5 -> V_22 , 1 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_2 , L_1 ) ;
return V_11 ;
}
V_10 = F_7 ( NULL , V_11 ) ;
if ( V_10 == V_23 ) {
F_6 ( & V_2 -> V_2 , L_2 ) ;
return - 1 ;
}
F_8 ( & V_2 -> V_2 , L_3 ,
V_11 , V_10 ) ;
F_9 ( V_10 ) ;
F_10 ( V_10 , V_7 ) ;
V_9 . V_24 = V_11 & V_25 ;
F_11 ( V_10 , & V_9 ) ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_11 ;
V_5 = F_2 ( V_2 -> V_12 ) ;
F_8 ( & V_2 -> V_2 , L_4 ) ;
F_4 (entry, &dev->msi_list, list) {
if ( V_7 -> V_26 == V_23 )
continue;
F_10 ( V_7 -> V_26 , NULL ) ;
F_13 ( V_7 -> V_26 ) ;
V_11 = F_14 ( V_7 -> V_26 ) ;
F_15 ( V_7 -> V_26 ) ;
F_16 ( V_5 -> V_22 , V_11 ) ;
}
}
void F_17 ( struct V_4 * V_5 )
{
F_18 ( V_5 -> V_27 + V_28 , V_29 ) ;
F_18 ( V_5 -> V_27 + V_30 , 1ull << 63 ) ;
V_31 . V_32 = F_1 ;
V_31 . V_33 = F_12 ;
}

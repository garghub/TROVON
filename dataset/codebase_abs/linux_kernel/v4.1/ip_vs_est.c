static void F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
int V_5 ;
bool V_6 = false ;
F_2 (i) {
struct V_3 * V_7 = F_3 ( V_4 , V_5 ) ;
unsigned int V_8 ;
T_2 V_9 , V_10 , V_11 , V_12 , V_13 ;
if ( V_6 ) {
do {
V_8 = F_4 ( & V_7 -> V_14 ) ;
V_9 = V_7 -> V_15 . V_9 ;
V_10 = V_7 -> V_15 . V_10 ;
V_11 = V_7 -> V_15 . V_11 ;
V_12 = V_7 -> V_15 . V_12 ;
V_13 = V_7 -> V_15 . V_13 ;
} while ( F_5 ( & V_7 -> V_14 , V_8 ) );
V_2 -> V_9 += V_9 ;
V_2 -> V_10 += V_10 ;
V_2 -> V_11 += V_11 ;
V_2 -> V_12 += V_12 ;
V_2 -> V_13 += V_13 ;
} else {
V_6 = true ;
do {
V_8 = F_4 ( & V_7 -> V_14 ) ;
V_2 -> V_9 = V_7 -> V_15 . V_9 ;
V_2 -> V_10 = V_7 -> V_15 . V_10 ;
V_2 -> V_11 = V_7 -> V_15 . V_11 ;
V_2 -> V_12 = V_7 -> V_15 . V_12 ;
V_2 -> V_13 = V_7 -> V_15 . V_13 ;
} while ( F_5 ( & V_7 -> V_14 , V_8 ) );
}
}
}
static void F_6 ( unsigned long V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_7 ;
T_2 V_20 ;
struct V_21 * V_21 = (struct V_21 * ) V_16 ;
struct V_22 * V_23 ;
V_23 = F_7 ( V_21 ) ;
F_8 ( & V_23 -> V_24 ) ;
F_9 (e, &ipvs->est_list, list) {
V_7 = F_10 ( V_18 , struct V_19 , V_25 ) ;
F_8 ( & V_7 -> V_26 ) ;
F_1 ( & V_7 -> V_27 , V_7 -> V_28 ) ;
V_20 = ( V_7 -> V_27 . V_9 - V_18 -> V_29 ) << 9 ;
V_18 -> V_29 = V_7 -> V_27 . V_9 ;
V_18 -> V_30 += ( ( V_31 ) V_20 - ( V_31 ) V_18 -> V_30 ) >> 2 ;
V_20 = ( V_7 -> V_27 . V_10 - V_18 -> V_32 ) << 9 ;
V_18 -> V_32 = V_7 -> V_27 . V_10 ;
V_18 -> V_33 += ( ( V_31 ) V_20 - ( V_31 ) V_18 -> V_33 ) >> 2 ;
V_20 = ( V_7 -> V_27 . V_11 - V_18 -> V_34 ) << 9 ;
V_18 -> V_34 = V_7 -> V_27 . V_11 ;
V_18 -> V_35 += ( ( V_31 ) V_20 - ( V_31 ) V_18 -> V_35 ) >> 2 ;
V_20 = ( V_7 -> V_27 . V_12 - V_18 -> V_36 ) << 4 ;
V_18 -> V_36 = V_7 -> V_27 . V_12 ;
V_18 -> V_37 += ( ( V_31 ) V_20 - ( V_31 ) V_18 -> V_37 ) >> 2 ;
V_20 = ( V_7 -> V_27 . V_13 - V_18 -> V_38 ) << 4 ;
V_18 -> V_38 = V_7 -> V_27 . V_13 ;
V_18 -> V_39 += ( ( V_31 ) V_20 - ( V_31 ) V_18 -> V_39 ) >> 2 ;
F_11 ( & V_7 -> V_26 ) ;
}
F_11 ( & V_23 -> V_24 ) ;
F_12 ( & V_23 -> V_40 , V_41 + 2 * V_42 ) ;
}
void F_13 ( struct V_21 * V_21 , struct V_19 * V_4 )
{
struct V_22 * V_23 = F_7 ( V_21 ) ;
struct V_17 * V_25 = & V_4 -> V_25 ;
F_14 ( & V_25 -> V_43 ) ;
F_15 ( & V_23 -> V_24 ) ;
F_16 ( & V_25 -> V_43 , & V_23 -> V_44 ) ;
F_17 ( & V_23 -> V_24 ) ;
}
void F_18 ( struct V_21 * V_21 , struct V_19 * V_4 )
{
struct V_22 * V_23 = F_7 ( V_21 ) ;
struct V_17 * V_25 = & V_4 -> V_25 ;
F_15 ( & V_23 -> V_24 ) ;
F_19 ( & V_25 -> V_43 ) ;
F_17 ( & V_23 -> V_24 ) ;
}
void F_20 ( struct V_19 * V_4 )
{
struct V_17 * V_25 = & V_4 -> V_25 ;
struct V_1 * V_45 = & V_4 -> V_27 ;
V_25 -> V_36 = V_45 -> V_12 ;
V_25 -> V_38 = V_45 -> V_13 ;
V_25 -> V_29 = V_45 -> V_9 ;
V_25 -> V_32 = V_45 -> V_10 ;
V_25 -> V_34 = V_45 -> V_11 ;
V_25 -> V_30 = 0 ;
V_25 -> V_33 = 0 ;
V_25 -> V_35 = 0 ;
V_25 -> V_37 = 0 ;
V_25 -> V_39 = 0 ;
}
void F_21 ( struct V_1 * V_46 , struct V_19 * V_4 )
{
struct V_17 * V_18 = & V_4 -> V_25 ;
V_46 -> V_30 = ( V_18 -> V_30 + 0x1FF ) >> 10 ;
V_46 -> V_33 = ( V_18 -> V_33 + 0x1FF ) >> 10 ;
V_46 -> V_35 = ( V_18 -> V_35 + 0x1FF ) >> 10 ;
V_46 -> V_37 = ( V_18 -> V_37 + 0xF ) >> 5 ;
V_46 -> V_39 = ( V_18 -> V_39 + 0xF ) >> 5 ;
}
int T_3 F_22 ( struct V_21 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_21 ) ;
F_14 ( & V_23 -> V_44 ) ;
F_23 ( & V_23 -> V_24 ) ;
F_24 ( & V_23 -> V_40 , F_6 , ( unsigned long ) V_21 ) ;
F_12 ( & V_23 -> V_40 , V_41 + 2 * V_42 ) ;
return 0 ;
}
void T_4 F_25 ( struct V_21 * V_21 )
{
F_26 ( & F_7 ( V_21 ) -> V_40 ) ;
}

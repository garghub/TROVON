int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_8 ;
int V_9 = 0 ;
V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
if ( ! V_4 )
return - V_10 ;
if ( V_4 -> V_11 != V_12 )
return - V_13 ;
V_6 = V_4 -> V_6 ;
F_3 ( V_14 , V_15 , FALSE ) ;
V_8 = V_6 -> V_16 . V_17 / 8 ;
V_7 = ( T_1 * ) V_6 -> V_18 . V_19 ;
V_7 += V_6 -> V_16 . V_20 * V_8 +
V_6 -> V_16 . V_21 * V_6 -> V_18 . V_22 ;
F_4 ( V_23 + 0xC0008 , ( V_24 ) V_7 >> 3 ) ;
F_3 ( V_25 , V_15 , FALSE ) ;
F_4 ( V_23 + 0xC0004 , 0x4c60674 ) ;
F_4 ( V_23 + 0xC0010 , 0x20 ) ;
F_4 ( V_23 + 0xC0018 , 0xeb0010 ) ;
F_4 ( V_23 + 0xC001C , 0xf00010 ) ;
F_4 ( V_23 + 0xC0020 , 0xf00010 ) ;
F_4 ( V_23 + 0xC000C , 0x67686970 ) ;
F_4 ( V_23 + 0xC0000 , 0x1 ) ;
F_3 ( V_14 , V_26 , FALSE ) ;
V_9 = F_5 ( V_2 ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_3 ( V_14 , V_15 , FALSE ) ;
F_4 ( V_23 + 0xC0000 , 0x0 ) ;
F_3 ( V_14 , V_26 , FALSE ) ;
F_3 ( V_25 , V_26 , FALSE ) ;
F_8 ( 100 ) ;
return V_9 ;
}
void F_9 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_7 ;
int V_8 ;
unsigned long V_27 ;
if ( ! V_4 -> V_28 )
return;
V_8 = V_6 -> V_16 . V_17 / 8 ;
V_7 = ( T_1 * ) V_6 -> V_18 . V_19 ;
V_7 += V_6 -> V_16 . V_20 * V_8 +
V_6 -> V_16 . V_21 * V_6 -> V_18 . V_22 ;
F_4 ( V_23 + 0xC0008 , ( V_24 ) V_7 >> 3 ) ;
F_10 ( & V_29 , V_27 ) ;
F_11 ( V_30 ) ;
F_12 ( V_4 -> V_31 -> V_32 ) ;
V_4 -> V_31 -> V_33 = TRUE ;
F_13 ( V_34 , V_35 ) ;
V_36 |= V_35 ;
F_13 ( V_37 , V_36 ) ;
F_14 ( & V_29 , V_27 ) ;
F_15 ( & V_4 -> V_31 -> V_32 ) ;
F_16 ( V_30 ) ;
}

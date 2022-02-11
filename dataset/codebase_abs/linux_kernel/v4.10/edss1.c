char * F_1 ( T_1 V_1 )
{
struct V_2 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_1 ; V_3 ++ )
if ( V_3 -> V_1 == V_1 )
break;
return V_3 -> V_5 ;
}
static void F_2 ( unsigned long V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) V_6 ;
F_3 ( & V_10 -> V_11 ) ;
V_10 -> V_11 . V_12 = NULL ;
V_8 = F_4 ( V_10 ) ;
if ( ! V_8 ) {
F_5 ( V_13 L_1 ) ;
return;
}
F_6 ( V_8 , V_10 , V_14 , NULL ) ;
}
void F_6 ( struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned short V_15 , struct V_16 * V_6 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
unsigned long V_21 ;
F_7 ( & V_8 -> V_22 , V_21 ) ;
for ( V_18 = V_23 ; V_18 -> V_24 != 0xff ; V_18 ++ )
if ( V_18 -> V_24 == V_10 -> V_25 && V_18 -> V_15 == V_15 )
break;
if ( V_18 -> V_24 == 0xff ) {
F_8 ( & V_8 -> V_22 , V_21 ) ;
F_5 ( V_26 L_2 ,
V_15 , V_10 -> V_25 ) ;
return;
}
if ( V_10 -> V_11 . V_12 ) {
F_3 ( & V_10 -> V_11 ) ;
V_10 -> V_11 . V_12 = NULL ;
}
V_10 -> V_25 = V_18 -> V_27 ;
F_9 ( V_8 , V_10 , V_18 -> V_24 , V_15 , V_18 -> V_27 ) ;
for ( V_20 = V_28 ; V_20 -> V_24 != 0xff ; V_20 ++ )
if ( V_20 -> V_24 == V_10 -> V_25 )
break;
if ( V_20 -> V_24 != 0xff ) {
F_10 ( & V_10 -> V_11 , & F_2 , ( V_29 ) V_10 ) ;
F_11 ( & V_10 -> V_11 , V_30 + V_20 -> V_31 * V_32 ) ;
}
F_8 ( & V_8 -> V_22 , V_21 ) ;
if ( V_18 -> V_33 )
V_18 -> V_33 ( V_8 , V_10 , V_6 ) ;
}

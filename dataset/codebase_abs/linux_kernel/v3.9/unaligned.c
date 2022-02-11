static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( ( V_2 -> V_8 == 1 ) || ( V_2 -> V_8 == 2 ) ) {
F_2 ( V_2 -> V_9 , V_2 -> V_10 + V_2 -> V_11 , V_4 , V_6 ) ;
if ( V_2 -> V_8 == 2 )
V_2 -> V_11 = 0 ;
}
if ( V_2 -> V_12 == 0 ) {
F_3 ( V_7 , V_2 -> V_10 + V_2 -> V_11 ) ;
} else {
F_4 ( V_7 , V_2 -> V_10 + V_2 -> V_11 ) ;
if ( V_2 -> V_13 )
V_7 = ( V_7 << 16 ) >> 16 ;
}
if ( V_2 -> V_14 == 0 )
F_2 ( V_2 -> V_15 , V_7 , V_4 , V_6 ) ;
return;
V_16: V_2 -> V_16 = 1 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ( V_2 -> V_8 == 1 ) || ( V_2 -> V_8 == 2 ) ) {
F_2 ( V_2 -> V_9 , V_2 -> V_11 + V_2 -> V_17 , V_4 , V_6 ) ;
if ( V_2 -> V_8 == 3 )
V_2 -> V_17 = 0 ;
} else if ( V_2 -> V_8 == 3 ) {
if ( V_2 -> V_12 == 2 ) {
F_2 ( V_2 -> V_9 , V_2 -> V_11 + ( V_2 -> V_17 << 1 ) ,
V_4 , V_6 ) ;
} else if ( ! V_2 -> V_12 ) {
F_2 ( V_2 -> V_9 , V_2 -> V_11 + ( V_2 -> V_17 << 2 ) ,
V_4 , V_6 ) ;
} else {
goto V_16;
}
}
if ( ! V_2 -> V_12 )
F_6 ( V_2 -> V_10 , V_2 -> V_11 + V_2 -> V_17 ) ;
else
F_7 ( V_2 -> V_10 , V_2 -> V_11 + V_2 -> V_17 ) ;
return;
V_16: V_2 -> V_16 = 1 ;
}
int F_8 ( unsigned long V_18 , struct V_3 * V_4 ,
unsigned long V_19 , struct V_5 * V_6 )
{
struct V_1 V_2 ;
char V_20 [ V_21 ] ;
if ( ! F_9 ( V_4 ) || ! V_22 )
return 1 ;
if ( V_23 ) {
F_10 ( L_1
L_2
L_3
L_4
L_5 ,
F_11 ( V_20 , V_24 ) , F_12 ( V_24 ) ) ;
} else {
F_13 ( L_6 ,
F_11 ( V_20 , V_24 ) , F_12 ( V_24 ) ,
V_18 , V_4 -> V_25 ) ;
}
F_14 ( V_4 -> V_25 , & V_2 , 1 , V_4 , V_6 ) ;
if ( V_2 . V_16 )
goto V_16;
if ( ( V_2 . V_12 == 1 ) || ( V_2 . V_26 ) )
goto V_16;
if ( ! V_2 . V_27 )
F_1 ( & V_2 , V_4 , V_6 ) ;
else
F_5 ( & V_2 , V_4 , V_6 ) ;
if ( V_2 . V_16 )
goto V_16;
if ( F_15 ( V_4 ) ) {
V_4 -> V_25 = V_4 -> V_28 ;
V_4 -> V_29 &= ~ V_30 ;
} else {
V_4 -> V_25 += V_2 . V_31 ;
}
return 0 ;
V_16:
F_16 ( L_7 ,
V_2 . V_32 [ 0 ] , V_18 ) ;
return 1 ;
}

static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_4 -> V_7 [ 2 ] |= ( V_6 -> V_8 << 5 ) & 0xE0 ;
V_4 -> V_7 [ 2 ] |= ( V_6 -> V_9 << 1 ) & 0x0E ;
F_3 ( V_2 ) ;
F_4 ( V_4 , V_6 -> V_10 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 , * V_11 ;
unsigned short V_12 , V_13 ;
if ( V_6 -> V_14 != V_15 )
return;
if ( V_6 -> V_16 & V_17 )
return;
if ( ! F_6 ( & V_2 -> V_18 ) )
return;
V_12 = ( F_6 ( & V_6 -> V_19 ) == NULL ) ? V_6 -> V_20 : V_6 -> V_9 ;
V_13 = ( V_6 -> V_20 + V_21 ) % V_22 ;
if ( V_12 == V_13 )
return;
V_6 -> V_9 = V_12 ;
V_4 = F_7 ( & V_2 -> V_18 ) ;
do {
if ( ( V_11 = F_8 ( V_4 , V_23 ) ) == NULL ) {
F_9 ( & V_2 -> V_18 , V_4 ) ;
break;
}
F_10 ( V_11 , V_2 ) ;
F_1 ( V_2 , V_11 ) ;
V_6 -> V_9 = ( V_6 -> V_9 + 1 ) % V_22 ;
F_11 ( & V_6 -> V_19 , V_4 ) ;
} while ( V_6 -> V_9 != V_13 &&
( V_4 = F_7 ( & V_2 -> V_18 ) ) != NULL );
V_6 -> V_24 = V_6 -> V_8 ;
V_6 -> V_16 &= ~ V_25 ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_16 & V_26 )
F_14 ( V_2 , V_27 ) ;
else
F_14 ( V_2 , V_28 ) ;
V_6 -> V_24 = V_6 -> V_8 ;
V_6 -> V_16 &= ~ V_25 ;
F_12 ( V_2 ) ;
}

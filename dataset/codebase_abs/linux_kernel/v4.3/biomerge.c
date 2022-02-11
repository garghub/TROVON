bool F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
unsigned long V_4 = F_2 ( F_3 ( V_2 -> V_5 ) ) ;
unsigned long V_6 = F_2 ( F_3 ( V_3 -> V_5 ) ) ;
return F_4 ( V_2 , V_3 ) &&
( ( V_4 == V_6 ) || ( ( V_4 + 1 ) == V_6 ) ) ;
}
